#
# If we list all the natural numbers below 10 that
# are multiples of 3 or 5, we get 3, 5, 6 and 9. The
# sum of these multiples is 23.
#
# Find the sum of all the multiples of 3 or 5 below
# 1000.
#

def sum_multiples(multiple1, multiple2, max):
    sum = 0
    for n in range(0, max):
        if (n % multiple1) == 0 or (n % multiple2) == 0:
            sum += n
    return sum

print("The sum of all multiples of 3 or 5 below 1000 is " + str(sum_multiples(3, 5, 1000)))

