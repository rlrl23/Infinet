import sys
import textfsm
from tabulate import tabulate

template = "template.txt"
output_file = sys.argv[1]

with open(template) as f, open(output_file) as output:
    re_table = textfsm.TextFSM(f)
    header = re_table.header
    result = re_table.ParseText(output.read())

    print(dict(zip(header, map(lambda x: int(x) if x.isdigit() else x,
                               *result))))
    print(tabulate(result, headers=header))
