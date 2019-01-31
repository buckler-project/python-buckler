import sys, os, pprint
import unittest

sys.path.append(os.pardir)
import buckler

class TestBuckler(unittest.TestCase):
    def test_hit(self):
        bk = buckler.Buckler()

        has_hit = bk.scan(b'hello\nworld')
        self.assertTrue(has_hit)
        
        hits = bk.hits()
        pprint.pprint(hits);
        self.assertEqual(
            [{
                'scanner': '.scanners//buckler-project/sample-scanner',
                'signature_file': '.signatures//buckler-project/first/1.line',
                'signatures': '.signatures//buckler-project/first'
            }],
            hits
        )

    def test_unhit(self):
        bk = buckler.Buckler()
        
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
