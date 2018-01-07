# -*- coding: utf-8 -*-
import re

def get_least_num_alphabet(name_str, dest_list):
    for i, alphabet in enumerate(list(name_str)):
        print i, alphabet



def get_order_child_str(mather_str):
    if not len(mather_str):
        return ['']
    rest_res_list = get_order_child_str(mather_str[1:])
    conn_rest_res_list = [mather_str[0] + rest_res for rest_res in rest_res_list]
    conn_rest_res_list += rest_res_list

    return conn_rest_res_list


def is_sub_str(mather_str, sub_str, num_str='0123456789abcefghijklmn'):
    num_str = num_str[0:len(mather_str)]
    print 'num str: ', num_str
    convert_dict = {}
    for i, alphabet in enumerate(list(num_str)):
        convert_dict[alphabet] = i
    res_list = get_order_child_str(num_str)
    print 'Total : ', len(res_list), res_list
    res_list = [res for res in res_list if len(res) == len(sub_str)]
    print 'Len OK : ', len(res_list), res_list

    res_dict = {}
    for res in res_list:
        res_str = [mather_str[convert_dict[alphabet]] for alphabet in list(res)]
        res_str = ''.join(res_str)
        if res_str == sub_str:
            res_dict[res] = res_str

    print 'GET : ', len(res_dict.keys()), res_dict
    return True if res_dict else False

A1 = "cahren"
B1 = "yran"
C1 = "fang"


def Combination(A1, B1):
    A1_list = list(A1)
    B1_list = list(B1)
    Common_list = [item for item in A1_list if item in B1_list]
    # 1 对Common_list中每个元素C分别单独考虑
    # 2 令 D = A1UB1-C
    # 3 若 D包含A1且包含B1，则保存该结果
    # 4 否则取下一个C
    res = []
    index_res = []
    for item in Common_list:
        inner_res = []
        inner__index_res = []
        index_list = [A1_list.index(a) for a in A1_list if a == item]
        for index in index_list:
            copy_A1_list = list(A1_list)
            copy_A1_list = [item for c_index, item in enumerate(copy_A1_list) if c_index != index]
            A_str = ''.join(copy_A1_list) + B1
            AC_list = [A_item for A_item in list(A_str) if A_item in A1_list]
            AC_str = ''.join(AC_list)
            # if A1 not in AC_str:
            #     continue
            if not is_sub_str(AC_str, A1):
                continue
            BC_list = [A_item for A_item in list(A_str) if A_item in B1_list]
            BC_str = ''.join(BC_list)
            # if B1 not in BC_str:
            #     continue
            if not is_sub_str(BC_str, B1):
                continue
            print 'find: ', index, A1[index]
            inner_res.append(A_str)
            inner__index_res.append(index)
        if not inner_res:
            print "NOTE: cant: ", index, A1[index]
        res.append(inner_res)
        index_res.append(inner__index_res)
    print 'res: ', res
    print 'index res: ', index_res
    i_list = []
    for index in index_res:
        i_list += index
    print i_list
    new_A1_list = [item for i, item in enumerate(A1_list) if i not in i_list]
    final = ''.join(new_A1_list) + B1
    print final

    return res, index_res, final

A1 = "ma"
B1 = "shuang"

name_str = 'chenegcnheg'  # 'chenyanfang'
sub_str = "chen"
# print is_sub_str(name_str, sub_str)
res, index_res, final = Combination(A1, B1)
C1 = 'hua'
Combination(final, C1)
