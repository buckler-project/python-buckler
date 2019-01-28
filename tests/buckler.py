import sys, os, pprint
import unittest

sys.path.append(os.pardir)

from bin import buckler

class TestBuckler(unittest.TestCase):
    def test_hit(self):
        bk = buckler.buckler()

        has_hit = bk.scan(b'hello\nworld')
        self.assertTrue(has_hit)
        
        hits = bk.hits()
        pprint.pprint(hits);
        self.assertEqual(
            [{
                'scanner': '.scanners/sample-scanner',
                'signature_file': '.signatures/first/1.line',
                'signatures': '.signatures/first'
            }],
            hits
        )

    def test_unhit(self):
        bk = buckler.buckler()
        
        has_hit = bk.scan(b'hoge\nhoge')
        self.assertFalse(has_hit)
        
        hits = bk.hits()
        pprint.pprint(hits);
        self.assertEqual(
            [],
            hits
        )

if __name__ == "__main__":
    unittest.main()
