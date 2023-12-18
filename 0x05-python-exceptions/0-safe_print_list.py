#!/usr/bin/python3

def safe_print_list(my_list=[], x=0):
    sum_total = 0
    index = 0

    while index < x:
        try:
            print(my_list[index], end="")
            sum_total += 1
        except IndexError:
            break
        else:
            index += 1

    print()
    return sum_total

