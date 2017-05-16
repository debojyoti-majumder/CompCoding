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

def get_permutations(input):
    input_length = len(input)
    permutation_sets = []
    
    # First handel the base cases
    if len(input) == 0:
        return []

    if len(input) == 1:
        return [input]

    for i in range(input_length):
        moving_item = input[i]
        remaining_items = input[:i] + input[i+1:]

        for p in get_permutations(remaining_items):
            permutation_sets.append([moving_item] + p)

    return permutation_sets;

def find_max_sum(problem_queue):
    item = []
    to_be_tested = []
    possible_solutions = []

    while not problem_queue.empty():
        item = problem_queue.get()

        if is_divisable_by_three(item):
            possible_solutions.append(item)
        else:
            to_be_tested.append(item)

    if len(possible_solutions) == 0 :
        for so in to_be_tested:
            # Constructing the subset
            for n in so:
                sub_solution = item.copy()
                sub_solution.remove(n)

                problem_queue.put(sub_solution)
        
        # Recursive call to do BFS
        return find_max_sum(problem_queue)
    else:
        max_val = 0

        for sol in possible_solutions:
            perm_set = get_permutations(sol)
                
            for p in perm_set:
                value = get_int_value_from_array(p)
                if value > max_val:
                    max_val = value

        return max_val

def problem_solver(input_array):
    # Intializing the queue
    problem_queue = queue.Queue()
    problem_queue.put(input_array)

    # Passing the queue to the main method
    return find_max_sum(problem_queue)


# Test function calls, output shoud be an integer
print(problem_solver([3,1,4,1]))       # Expected output 4311
print(problem_solver([3,1,4,1,5,9]))   # Expected output 94311  
