#!/usr/bin/python

import json
from pprint import pprint

json_data=open("./data/opcodes.json").read()

opCodes = json.loads(json_data)

nonCBOpCodes = opCodes["unprefixed"]
cBOpCodes = opCodes["cbprefixed"]

print "#ifndef _OPCODES_H\n#define _OPCODES_H"
print "#include \"components.h\""
print "#define NUM_NORMAL_OPCODES 256"
print "#define NUM_CB_OPCODES 256"

opcodeFuncs = []
cbOpcodeFuncs = []

print "// unused func as placeholder"
print "void unusedFunc(cpu_t* cpu, mem_t* mem);\n"

print '// ================= NON-PREFIXED ============================='

for opcode in range(0,256):
    obj = None

    # quick and dirty
    for c in nonCBOpCodes.keys():
        if int(c,16) == opcode:
            obj = nonCBOpCodes[c]

    if obj == None:
        opcodeFuncs.append('unusedFunc')
        continue

    mnemonic = obj['mnemonic']

    name = mnemonic
    if 'operand1' in obj:
        name += ('_' + obj['operand1'].replace('(','_OP_').replace(')','_CP_').replace('+','_PLUS_').replace('-','_MINUS_'))

    if 'operand2' in obj:
        name += ('_' + obj['operand2'].replace('(','_OP_').replace(')','_CP_').replace('+','_PLUS_').replace('-','_MINUS_'))

    print "// cycles=" + str(obj['cycles'][0]) + ",addr=" + str(obj['addr']) + ',length=' + str(obj['length'])
    print "void " + name + "(cpu_t* cpu, mem_t* mem);\n"
    opcodeFuncs.append(name)

print '// ================== CB-PREFIXED ============================='

# cb
for opcode in range(0,256):
    obj = None

    # quick and dirty
    for c in cBOpCodes.keys():
        if int(c,16) == opcode:
            obj = cBOpCodes[c]

    if obj == None:
        cbOpcodeFuncs.append('unusedFunc')
        continue

    mnemonic = obj['mnemonic']

    name = 'cb_' + mnemonic
    if 'operand1' in obj:
        name += ('_' + obj['operand1'].replace('(','_OP_').replace(')','_CP_').replace('+','_PLUS_').replace('-','_MINUS_'))

    if 'operand2' in obj:
        name += ('_' + obj['operand2'].replace('(','_OP_').replace(')','_CP_').replace('+','_PLUS_').replace('-','_MINUS_'))

    print "// cycles=" + str(obj['cycles'][0]) + ",addr=" + str(obj['addr']) + ',length=' + str(obj['length'])
    print "void " + name + "(cpu_t* cpu, mem_t* mem);\n"
    cbOpcodeFuncs.append(name)


print "static const opcode_t normalOpcodes[NUM_NORMAL_OPCODES] = \n{"

for idx, func in enumerate(opcodeFuncs):
    if idx == len(opcodeFuncs):
        print '\t/*' + str(idx) + '*/ ' + '&' + func
    else:
        print '\t/*' + str(idx) + '*/ ' + '&' + func + ','

print '};\n\n'

print "static const opcode_t cbOpcodes[NUM_CB_OPCODES] = \n{"

for idx, func in enumerate(cbOpcodeFuncs):
    if idx == len(cbOpcodeFuncs):
        print '\t/*' + str(idx) + '*/ ' + '&' + func
    else:
        print '\t/*' + str(idx) + '*/ ' + '&' + func + ','

print '};\n\n'


print '#endif\n'