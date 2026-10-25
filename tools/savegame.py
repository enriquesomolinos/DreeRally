"""Lee, descifra, cifra y edita las partidas guardadas DR.SG0..DR.SG9 (version completa).

Formato en doc/SAVEGAME.md. Reemplaza a savegameDecrypt.py/savegameCrypt.py, que son de
Python 2 y escriben texto en lugar de bytes.

    python tools/savegame.py show runtime/DR.SG2
    python tools/savegame.py show runtime/DR.SG2 --all
    python tools/savegame.py decrypt runtime/DR.SG2 sg2.bin
    python tools/savegame.py encrypt sg2.bin runtime/DR.SG2
    python tools/savegame.py set runtime/DR.SG2 name="Light Gaby" money=5000
    python tools/savegame.py set runtime/DR.SG2 --driver 3 points=0

`set` edita al jugador salvo que se indique --driver, conserva la clave y deja una copia .bak.
"""
import argparse
import shutil
import struct
import sys

SIZE = 0x883  # 2179
HEADER = 19
DRIVERS = 20
DRIVER_SIZE = 108

# Campos de Driver (drivers.h) despues del nombre de 12 bytes, todos int32 little endian.
FIELDS = [
    "damage", "engine", "tire", "armour", "carType", "unk_460860", "unk_460864", "unk_460868",
    "colour", "money", "loanType", "loanRaces", "carMoneyCost", "face", "points", "rank",
    "racesWon", "totalRaces", "lastRaceIncome", "totalIncome", "mines", "spikes", "rocket", "sabotage",
]
DRIVER_FORMAT = "<12s24i"
assert struct.calcsize(DRIVER_FORMAT) == DRIVER_SIZE


def decrypt(raw):
    data = bytearray(raw)
    key = data[0]
    for i in range(1, SIZE):
        r = i % 6
        b = data[i]
        if r:
            b = ((b << r) | (b >> (8 - r))) & 0xFF
        data[i] = (b - 17 * i + key) & 0xFF
    return data


def encrypt(plain):
    data = bytearray(plain)
    key = data[0]
    for i in range(1, SIZE):
        r = i % 6
        b = (data[i] - key + 17 * i) & 0xFF
        if r:
            b = ((b >> r) | (b << (8 - r))) & 0xFF
        data[i] = b
    return data


def cstring(raw):
    return raw.split(b"\0", 1)[0].decode("latin-1")


def parse(plain):
    save = {
        "key": plain[0],
        "driverId": plain[1],
        "useWeapons": plain[2],
        "difficulty": plain[3],
        "saveName": cstring(bytes(plain[4:HEADER])),
        "drivers": [],
    }
    for n in range(DRIVERS):
        values = struct.unpack_from(DRIVER_FORMAT, plain, HEADER + n * DRIVER_SIZE)
        driver = {"name": cstring(values[0])}
        driver.update(zip(FIELDS, values[1:]))
        save["drivers"].append(driver)
    return save


def setField(plain, index, field, value):
    offset = HEADER + index * DRIVER_SIZE
    if field == "name":
        name = value.encode("latin-1")
        if len(name) > 11:
            raise ValueError("el nombre admite 11 letras como maximo (12 bytes con el cero)")
        plain[offset:offset + 12] = name.ljust(12, b"\0")
    elif field in FIELDS:
        struct.pack_into("<i", plain, offset + 12 + 4 * FIELDS.index(field), int(value))
    else:
        raise ValueError("campo desconocido: " + field)


def read(path):
    raw = open(path, "rb").read()
    if len(raw) != SIZE:
        sys.exit("%s mide %d bytes; se esperaban %d (version completa)" % (path, len(raw), SIZE))
    return raw


def show(save, everyone):
    print("partida %r, dificultad %d, armas %d, jugador drivers[%d]" % (
        save["saveName"], save["difficulty"], save["useWeapons"], save["driverId"]))
    for n, driver in enumerate(save["drivers"]):
        if not everyone and n != save["driverId"]:
            continue
        mark = "*" if n == save["driverId"] else " "
        print("%s%2d %-11s" % (mark, n, driver["name"]),
              " ".join("%s=%d" % (f, driver[f]) for f in FIELDS))


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    commands = parser.add_subparsers(dest="command", required=True)
    p = commands.add_parser("show")
    p.add_argument("file")
    p.add_argument("--all", action="store_true", help="todos los pilotos, no solo el jugador")
    for name in ("decrypt", "encrypt"):
        p = commands.add_parser(name)
        p.add_argument("source")
        p.add_argument("dest")
    p = commands.add_parser("set")
    p.add_argument("file")
    p.add_argument("--driver", type=int, help="indice en drivers[]; por defecto el jugador")
    p.add_argument("assignments", nargs="+", metavar="campo=valor")
    args = parser.parse_args()

    if args.command == "show":
        show(parse(decrypt(read(args.file))), args.all)
    elif args.command == "decrypt":
        open(args.dest, "wb").write(decrypt(read(args.source)))
    elif args.command == "encrypt":
        open(args.dest, "wb").write(encrypt(read(args.source)))
    else:
        plain = decrypt(read(args.file))
        index = plain[1] if args.driver is None else args.driver
        for assignment in args.assignments:
            field, _, value = assignment.partition("=")
            setField(plain, index, field, value)
        shutil.copyfile(args.file, args.file + ".bak")
        open(args.file, "wb").write(encrypt(plain))
        show(parse(plain), False)


if __name__ == "__main__":
    main()
