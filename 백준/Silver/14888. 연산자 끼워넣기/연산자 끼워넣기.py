global small
global big

small = 100000000000000000000000
big = -100000000000000000000

def cal(oper, result, nums, index):
    global small, big
    if index == len(nums):
        if result > big:
            big = result
        if result < small:
            small = result
        return
    for i in range(4):
        if oper[i] == 0:
            continue
        oper[i] -= 1
        if i == 0:
            cal(oper, result + nums[index], nums, index + 1)
        elif i == 1:
            cal(oper, result - nums[index], nums, index + 1)
        elif i == 2:
            cal(oper, result * nums[index], nums, index + 1)
        else:
            # temp = result
            # if result < 0:
            #     result = -(-result // nums[index])
            # else:
            #     result //= nums[index]
            cal(oper, int(result / nums[index]), nums, index + 1)
            # result = temp
        oper[i] += 1

size = int(input())
nums = list(map(int,input().split()))
operator = list(map(int,input().split()))

cal(operator, nums[0], nums, 1)

print(big)
print(small)