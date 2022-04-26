import os, sys
import numpy as np
import random as rd
import string



NS=[ 'std' ]


try:
    gns=sys.argv[1]
except :
    quit('please specify the namespace ( \'std\' or \'ft\' )')

TYPE={
    'char': {
        'range': [ [ np.arange(-10, 10), [ -128, 127 ] ] ] * 2,
        'fill': [ np.arange(-10, 10), [ -128, 127 ] ]
    },
    'int': {
        'range': [ [ np.arange(-10, 10), [ -2147483648, 2147483647 ] ] ] * 2,
        'fill' : [ np.arange(-10, 10), [-2147483648, 2147483647] ]
    },
    'unsigned int': {
        'range': [ [ np.arange(10), [ 4294967295 ] ] ] * 2,
        'fill': [ np.arange(-10, 10), [ 4294967295 ] ]
    },
    'long long': {
        'range': [ [ np.arange(-10, 10), [ -9223372036854775808, 9223372036854775807 ] ] ] * 2,
        'fill': [ np.arange(-10, 10), [ -9223372036854775808, 9223372036854775807 ] ]
    },
    'float': {
        'range': [ [ np.arange(-5.0, 5.0, 0.2), [ -1.0, 0.0, 1.0 ] ] ] * 2,
        'fill': [ np.arange(-5.0, 5.0, 0.2), [ -1.0, 0.0, 1.0 ] ]
    },
    'std::string': {
        'range': [ [ np.arange(10) ], [ np.arange(10), np.array([ 20, 50, 1000, 10000 ]) ] ],
        'fill': [ np.arange(10) ]
    }
}

PATTERN_TOP=\
'\
#include <iostream>\n\
#include <vector>\n\
#include "vector.hpp"\n\
\n\
int main(void)\n\
{\n\
'

PATTERN_BOT=\
'\n\
\treturn (0);\n\
}\n\
'

VECTOR_PATTERN = {
    'vector': '::vector',
    'before_type': '<',
    'after_type': '>',
    'iterator': '::iterator',
    'const_iterator': '::const_iterator',
    'lpar': '(',
    'rpar': ')'
}


def rand_string(size, ranged, quoted=False):
    ret = ''
    if quoted:
        ret += '\"'
    for _ in range(size):
        t = chr(rd.choice(ranged))
        if t == '\"' or t == '\'' or t == '\\':
            ret += '\\'
        ret += t
    if quoted:
        ret += '\"'
    return ret

def new_varname():
    return rand_string(30, range(97, 123))

def vector_contructor():
    for val_type, args in TYPE.items():
        # base
        varname = new_varname()
        yield (varname, gns \
        + VECTOR_PATTERN['vector'] \
        + VECTOR_PATTERN['before_type'] \
        + val_type \
        + VECTOR_PATTERN['after_type'] \
        + ' ' + varname)

        # range
        for a in args['range'][0]:
            for b in args['range'][1]:
                for aa in a:
                    for bb in b:
                        varname = new_varname()
                        yield (varname, gns \
                        + VECTOR_PATTERN['vector'] \
                        + VECTOR_PATTERN['before_type'] \
                        + val_type \
                        + VECTOR_PATTERN['after_type'] \
                        + ' ' + varname \
                        + VECTOR_PATTERN['lpar'] \
                        + (str(aa) if val_type != 'float' else ('float(' + str(aa) + ')')) \
                        + ', ' \
                        + (rand_string(bb, range(32, 127), True) if val_type == 'std::string' else (str(bb) if val_type != 'float' else ('float(' + str(bb) + ')'))) \
                        + VECTOR_PATTERN['rpar'])

        # fill
        for a in args['fill']:
            for aa in a:
                varname = new_varname()
                yield (varname, gns \
                + VECTOR_PATTERN['vector'] \
                + VECTOR_PATTERN['before_type'] \
                + val_type \
                + VECTOR_PATTERN['after_type'] \
                + ' ' + varname \
                + VECTOR_PATTERN['lpar'] \
                + (str(aa) if val_type != 'float' else ('float(' + str(aa) + ')')) \
                + VECTOR_PATTERN['rpar'])

def create_ret_variable(vartype, varname=None):
    if varname == None:
        varname = new_varname()
    ret = gns + '::' + vartype + ' ' + varname
    return (varname,ret)

def print_variable(varname, vartype): # vartype should be one of: 'address' or 'value'
    if vartype == 'address':
        ret = 'std::cout << *' + varname + ' << std::endl'
    elif vartype == 'value':
        ret = 'std::cout << ' + varname + ' << std::endl'
    return ret


def add_line(s):
    return s + ';' + '\n\t'

##########################################################################

def gen_begin(varname):
    yield ''
    variable, line = create_ret_variable('iterator')
    line += ' = ' + varname + '.begin()'
    ret = add_line(line) + add_line(print_variable(variable, 'address'))
    yield ret

    variable, line = create_ret_variable('const_iterator')
    line += ' = ' + varname + '.begin()'
    ret = add_line(line) + add_line(print_variable(variable, 'address'))
    yield ret

def gen_end(varname, val_type):
    yield ''
    ret = varname + '.end('

    ret += ')'
    yield ret

def gen_rbegin(varname, val_type):
    yield ''
    ret = varname + '.rbegin('

    ret += ')'
    yield ret

def gen_rend(varname, val_type):
    yield ''
    ret = varname + '.rend('

    ret += ')'
    yield ret

def gen_size(varname, val_type):
    yield ''
    ret = varname + '.size('

    ret += ')'
    yield ret

def gen_max_size(varname, val_type):
    yield ''
    ret = varname + '.max_size('

    ret += ')'
    yield ret

def gen_resize(varname, val_type):
    yield ''
    ret = varname + '.resize('

    ret += ')'
    yield ret

def gen_capacity(varname, val_type):
    yield ''
    ret = varname + '.capacity('

    ret += ')'
    yield ret

def gen_empty(varname, val_type):
    yield ''
    ret = varname + '.empty('

    ret += ')'
    yield ret

def gen_reserve(varname, val_type):
    yield ''
    ret = varname + '.reserve('

    ret += ')'
    yield ret

def gen_at(varname, val_type):
    yield ''
    ret = varname + '.at('

    ret += ')'
    yield ret

def gen_front(varname, val_type):
    yield ''
    ret = varname + '.front('

    ret += ')'
    yield ret

def gen_back(varname, val_type):
    yield ''
    ret = varname + '.back('

    ret += ')'
    yield ret

def gen_assign(varname, val_type):
    yield ''
    ret = varname + '.assign('

    ret += ')'
    yield ret

def gen_push_back(varname, val_type):
    yield ''
    ret = varname + '.push_back('

    ret += ')'
    yield ret

def gen_pop_back(varname, val_type):
    yield ''
    ret = varname + '.pop_back('

    ret += ')'
    yield ret

def gen_insert(varname, val_type):
    yield ''
    ret = varname + '.insert('

    ret += ')'
    yield ret

def gen_erase(varname, val_type):
    yield ''
    ret = varname + '.erase('

    ret += ')'
    yield ret

def gen_swap(varname, val_type):
    yield ''
    ret = varname + '.swap('

    ret += ')'
    yield ret

def gen_clear(varname, val_type):
    yield ''
    ret = varname + '.clear('

    ret += ')'
    yield ret

def gen_get_allocator(varname, val_type):
    yield ''
    ret = varname + '.get_allocator('

    ret += ')'
    yield ret

#### operators

def gen_operator_1(): # varname, val_type[]
    yield ''
    ret = ''
    yield ret

def gen_operator_2(): # varname, val_type==
    yield ''
    ret = ''
    yield ret

def gen_operator_3(): # varname, val_type!=
    yield ''
    ret = ''
    yield ret

def gen_operator_4(): #varname, val_type <
    yield ''
    ret = ''
    yield ret

def gen_operator_5(): # varname, val_type<=
    yield ''
    ret = ''
    yield ret

def gen_operator_6(): #varname, val_type >
    yield ''
    ret = ''
    yield ret

def gen_operator_7(): # varname, val_type>=
    yield ''
    ret = ''
    yield ret


##################################################################################

def init():
    f = open('test_001.cpp', 'x')
    f.write(PATTERN_TOP)
    f.write(test())
    f.write(PATTERN_BOT)

def build_ret(constructor, test_begin):
    ret = '\t'
    ret += add_line(constructor)
    ret += test_begin
    return ret

def gen_constructor():
    total = 0
    for varname, constructor in vector_contructor():
        for test_begin in gen_begin(varname):
            total += 1;yield build_ret(constructor, test_begin)
    print('total:', total)


####################################################

# init()

for constru in gen_constructor():
    print(constru)

# print(rand_string(10))
