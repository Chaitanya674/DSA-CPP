def calculate_valency(element):
    n = ord(element)
    for _ in range(2):
        ten = n // 10
        once = n % 10 
        n = ten + once
    return n

def balance_comp(compA , compB , equ):
    ans = []
    val_A = calculate_valency(compA)
    val_B = calculate_valency(compB)
    r = equ // val_A
    for i in range(1 , r+1):
        remain = equ - i * val_A
        if remain % val_B == 0:
            j = remain // val_B
            ans.append(f"{compA}{i} {compB}{j}")
    if len(ans) > 0 :
        for i in range(len(ans) - 2, -1, -1):
            print(ans[i])
    else:
        print("Not Possible")

# Read input
compA , compB = input().strip()
equ = int(input())

balance_comp(compA , compB , equ)