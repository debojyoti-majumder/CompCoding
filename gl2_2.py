import queue

def is_divisable_by_three(arr):
    sum = 0

    for number in arr:
        sum = sum + number
    
    if sum % 3 == 0:
        return True 
    else:
        return False

def get_int_value_from_array(array):
    sum = 0;
    length = len(array)

    for i in range(length):
        sum += (10 ** (length - 1 - i)) * array[i]

    return sum

def find_max_sum(problem_queue):
    # Base case
    if problem_queue.empty():
        return 0

    item = problem_queue.get()
    item.sort(reverse=True)

    if is_divisable_by_three(item):     
        return get_int_value_from_array(item)
    else:
        for n in reversed(item):
            possible_solution = item.copy()
            possible_solution.remove(n)

            problem_queue.put(possible_solution)
        
        return find_max_sum(problem_queue)
    return 0

def problem_solver(input_array):
    # Intializing the queue
    problem_queue = queue.Queue()
    problem_queue.put(input_array)

    # Passing the queue to the main method
    return find_max_sum(problem_queue)

# Test function calls, output shoud be an integer
print(problem_solver([3,1,4,1]))        # Expected output 4311
print(problem_solver([3,1,4,1,5,9]))    # Expected output 94311  
print(problem_solver([]))               # Expected output 0  
