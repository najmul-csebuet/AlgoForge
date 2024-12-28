# compare_files.py
def compare_files(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        lines1 = f1.readlines()
        lines2 = f2.readlines()
        
    mismatch = False
    for i, (line1, line2) in enumerate(zip(lines1, lines2), start=1):
        if line1 != line2:
            mismatch = True
            print(f"Difference found at line {i}:")
            print(f"     ans.txt: {line1.strip()}")
            print(f"     out.txt: {line2.strip()}")
    
    if len(lines1) > len(lines2):
        print(f"Extra lines in {file1} starting from line {len(lines2) + 1}")
    elif len(lines2) > len(lines1):
        print(f"Extra lines in {file2} starting from line {len(lines1) + 1}")

    if not mismatch:
        print("\n                >>>> All test cases passed <<<<") 

# Run the comparison
compare_files('ans.txt', 'out.txt')
