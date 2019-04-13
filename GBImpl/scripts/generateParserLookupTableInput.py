#!/usr/bin/python

import json
from pprint import pprint

json_data=open("./data/opcodes.json").read()

opCodes = json.loads(json_data)

nonCBOpCodes = opCodes["unprefixed"]
cBOpCodes = opCodes["cbprefixed"]

for opcode in range(0,256):
    obj = None

    # quick and dirty
    for c in nonCBOpCodes.keys():
        if int(c,16) == opcode:
            obj = nonCBOpCodes[c]

    if obj == None:
        continue
    # don't include PREFIX CB in output
    if obj['mnemonic'] == 'PREFIX':
        continue

    mnemonic = obj['mnemonic']

    name = mnemonic
    if 'operand1' in obj:
        name += ' ' + obj['operand1']

    if 'operand2' in obj:
        name += ' ' + obj['operand2']

    addr = str(obj['addr'][2::])
    if (len(addr) == 1):
        addr = "0" + addr

    print name
    print addr

# cb
for opcode in range(0,256):
    obj = None

    # quick and dirty
    for c in cBOpCodes.keys():
        if int(c,16) == opcode:
            obj = cBOpCodes[c]

    if obj == None:
        continue

    mnemonic = obj['mnemonic']

    name = mnemonic
    if 'operand1' in obj:
        name += ' ' + obj['operand1']

    if 'operand2' in obj:
        name += ' ' + obj['operand2']

    addr = str(obj['addr'][2::])
    if (len(addr) == 1):
        addr = "0" + addr

    print name
    print "cb" + addr
