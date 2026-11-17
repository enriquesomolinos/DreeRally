// Generates ui/util/keyNames.c: the key name tables dr.exe builds in code, one store at a time.
// sub_41CA40 (0x41CA40) fills 0x462DA0 for the define-keyboard menu and keyMenuInRace (0x407330)
// fills 0x4A6B20 for the in-race key screen, 256 keys of 15 bytes each. Both are emulated here
// and the tables dumped as they are after the stores.
//
//   analyzeHeadless <project dir> <project> -process dr.exe -noanalysis -readOnly
//       -scriptPath tools/ghidra -postScript DumpKeyNames.java ui/util/keyNames.c
//@category DreeRally

import java.io.PrintWriter;

import ghidra.app.emulator.EmulatorHelper;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

public class DumpKeyNames extends GhidraScript {

	private static final int KEYS = 256, NAME = 15;
	private static final long STACK = 0x2FFF0000L, RETURN = 0x0BADC0DEL;

	@Override
	protected void run() throws Exception {
		byte[] menu = emulate(0x41CA40, RETURN, 0x462DA0);
		// keyMenuInRace writes all its names before its first call (0x4087E1).
		byte[] race = emulate(0x407330, 0x4087E1, 0x4A6B20);
		try (PrintWriter out = new PrintWriter(getScriptArgs()[0], "ISO-8859-1")) {
			out.print("//Generado por tools/ghidra/DumpKeyNames.java desde el dr.exe original. No editar a mano.\n");
			out.print("#include \"keyNames.h\"\n\n");
			table(out, "originalKeyNames", "sub_41CA40, 0x462DA0: menu de definir teclado", menu);
			table(out, "originalKeyNamesInRace", "keyMenuInRace_407330, 0x4A6B20: pantalla de teclas en carrera", race);
		}
	}

	private byte[] emulate(long entry, long stop, long table) throws Exception {
		EmulatorHelper emu = new EmulatorHelper(currentProgram);
		try {
			emu.writeRegister(emu.getStackPointerRegister(), STACK);
			emu.writeMemoryValue(toAddr(STACK), 4, RETURN);
			emu.writeRegister(emu.getPCRegister(), entry);
			emu.setBreakpoint(toAddr(stop));
			if (!emu.run(monitor) || !emu.getExecutionAddress().equals(toAddr(stop))) {
				throw new Exception(String.format("emulation of %X stopped at %s: %s", entry,
					emu.getExecutionAddress(), emu.getLastError()));
			}
			return emu.readMemory(toAddr(table), KEYS * NAME);
		}
		finally {
			emu.dispose();
		}
	}

	private void table(PrintWriter out, String name, String comment, byte[] data) {
		out.printf("//%s\n", comment);
		out.printf("const char %s[%d][%d] = {\n", name, KEYS, NAME);
		for (int k = 0; k < KEYS; k++) {
			StringBuilder s = new StringBuilder();
			int end = NAME;
			while (end > 0 && data[k * NAME + end - 1] == 0) {
				end--;   // C fills the rest with zeros
			}
			for (int i = 0; i < end; i++) {
				int c = data[k * NAME + i] & 0xFF;
				s.append(c >= 0x20 && c < 0x7F && c != '"' && c != '\\' && c != '?'
						? Character.toString((char) c) : String.format("\\%03o", c));
			}
			out.printf("  \"%s\", //%d\n", s, k);
		}
		out.print("};\n\n");
	}
}
