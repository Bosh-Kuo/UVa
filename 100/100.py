from sys import stdin
limit = 10000000
memory = [None]*limit
memory[1]=1
memory[0]=0
def Recursive(n):
    if n < limit and memory[n] != None:
        return memory[n]
		
    count = ( Recursive(3*n+1) if n%2 else Recursive(n//2) ) + 1 
    if n < limit:
        memory[n] = count
    return count 

def find_max(down, up):
    max_value = 0
    down, up = min(down, up), max(down, up)
    for i in range(down, up+1):
        max_value = max(max_value, Recursive(i))
    return max_value
    
def main():
    for line in stdin:
        down, up = [int(inputNumber) for inputNumber in line.split()]
        print(down, up, find_max(down, up))

if __name__ == '__main__':
    main()
    # print(Recursive(22))
    