#!/usr/bin/python

import json
from pprint import pprint

json_data=open("./data/opcodes.json").read()

opCodes = json.loads(json_data)

nonCBOpCodes = opCodes["unprefixed"]
cBOpCodes = opCodes["cbprefixed"]

print "#include \"opcodes.h\""

print "// unused func as placeholder"
print "void unusedFunc(cpu_t* cpu, mem_t* mem){}"

print '// ================= NON-PREFIXED ============================='

for opcode in range(0,256):
    obj = None

    # quick and dirty
    for c in nonCBOpCodes.keys():
        if int(c,16) == opcode:
            obj = nonCBOpCodes[c]

    if obj == None:
        continue

    mnemonic = obj['mnemonic']

    name = mnemonic
    if 'operand1' in obj:
        name += ('_' + obj['operand1'].replace('(','_OP_').replace(')','_CP_').replace('+','_PLUS_').replace('-','_MINUS_'))

    if 'operand2' in obj:
        name += ('_' + obj['operand2'].replace('(','_OP_').replace(')','_CP_').replace('+','_PLUS_').replace('-','_MINUS_'))

    print "// cycles=" + str(obj['cycles'][0]) + ",addr=" + str(obj['addr']) + ',length=' + str(obj['length'])
    print "// flags:Z={0},N={1},H={2},C={3}".format(obj['flags'][0],obj['flags'][1],obj['flags'][2],obj['flags'][3])
    print "void " + name + "(cpu_t* cpu, mem_t* mem)\n{\n}\n"

print '// ================== CB-PREFIXED ============================='

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

    name = 'cb_' + mnemonic
    if 'operand1' in obj:
        name += ('_' + obj['operand1'].replace('(','_OP_').replace(')','_CP_').replace('+','_PLUS_').replace('-','_MINUS_'))

    if 'operand2' in obj:
        name += ('_' + obj['operand2'].replace('(','_OP_').replace(')','_CP_').replace('+','_PLUS_').replace('-','_MINUS_'))

    print "// cycles=" + str(obj['cycles'][0]) + ",addr=" + str(obj['addr']) + ',length=' + str(obj['length'])
    print "// flags:Z={0},N={1},H={2},C={3}".format(obj['flags'][0],obj['flags'][1],obj['flags'][2],obj['flags'][3])
    print "void " + name + "(cpu_t* cpu, mem_t* mem)\n{\n}\n"

