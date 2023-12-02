#!/usr/bin/python3

def main():
    """Handle basic arithmetic operations based on command-line arguments."""
    from calculator_1 import add, sub, mul, div
    import sys

    if len(sys.argv) != 4:
        print("Usage: ./100-my_calculator.py <a> <operator> <b>")
        sys.exit(1)

    operators = {"+": add, "-": sub, "*": mul, "/": div}
    operator = sys.argv[2]

    if operator not in operators:
        print("Unknown operator. Available operators: +, -, * and /")
        sys.exit(1)

    a = int(sys.argv[1])
    b = int(sys.argv[3])

    result = operators[operator](a, b)
    print("{} {} {} = {}".format(a, operator, b, result))

if __name__ == "__main__":
    main()
