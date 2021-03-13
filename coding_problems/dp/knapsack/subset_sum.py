def __subset__(numbers, size,target, mem):
    if(size == 0):
        return false
    if(target == 0):
        return true;
    if(mem[size][target]!= -1): 
        return mem[size][target]
    last_num = numbers[size]
    if(last_num>target):
        mem[size][target] = __subset__(numbers.pop(size),size-1,target)
    else:
        mem[size][target] = __subset__(numbers.pop(size),size -1, target + last_num) or __subset__(numbers.pop(size),size-1,target)


def subset( numbers,  target):
    mem[numbers+1][target+1]
    for i in range(0,numbers+1):
        for j in range(0,target+1):
            mem[i][j] = -1
    size = len(numbers)
    return __subset__(numbers,size,target,mem)

numbers = [2,3,7,8,10]
target = 11

print(subset(numbers,target))