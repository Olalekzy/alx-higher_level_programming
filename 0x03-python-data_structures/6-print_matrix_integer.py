#!/usr/bin/python3

def print_matrix_integer(matrix):
    if not matrix or not any(matrix):
        print()
    else:
        for row in matrix:
            for idx, item in enumerate(row):
                if idx != len(row) - 1:
                    endspace = ' '
                else:
                    endspace = '\n'
                print("{:d}".format(item), end=endspace)
