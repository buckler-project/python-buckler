# python-buckler
The wrapper of buckler for python.

## Getting Started

### Dependencies
Please install them before install buckler-python.

* [buckler](https://github.com/buckler-project/buckler)
* boost-python

And now, it support only Linux.  
(it will support Windows for the future.)

### Installing
Sorry. Installer will make for the future.


### Example
```python
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
```
