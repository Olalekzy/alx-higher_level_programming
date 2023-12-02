#!/usr/bin/python3

def perform_calculations(a, b):
    """Prints the sum, difference, product, and quotient of two numbers."""
    from calculator_1 import add, sub, mul, div

    print("{} + {} = {}".format(a, b, add(a, b)))
    print("{} - {} = {}".format(a, b, sub(a, b)))
    print("{} * {} = {}".format(a, b, mul(a, b)))
    print("{} / {} = {}".format(a, b, div(a, b)))

if __name__ == "__main__":
    """Main function to perform calculations with numbers."""
    a = 10
    b = 5

    perform_calculations(a, b)
