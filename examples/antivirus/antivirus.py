import sys
from buckler import Buckler
from pprint import pprint


def main(name):
    with open(name, 'rb') as f:
        body = f.read()

        buckler = Buckler()
        has_hit = buckler.scan(body)

        if has_hit:
            print(f"`{name}` is malware.")
        else:
            print(f"`{name}` is not malware.")


if __name__ == '__main__':
    if len(sys.argv) <= 1:
        sys.exit("[err] argument incorrect.")

    main(sys.argv[1])
