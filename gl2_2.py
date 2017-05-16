import queue

def is_divisable_by_three(arr):
    sum = 0

    for number in arr:
        sum = sum + number
    
    if sum % 3 == 0:
        return True
    else:
        return False

def get_permutations(input):
    input_length = len(input)
    permutation_sets = []
    permutation_sets.append(input)

    for i in range(input_length):
        for j in range(input_length):
            if not i == j:
                # Create the new item
                temp_array = input.copy()
                
                # Swap the two numbers
                t = temp_array[i]
                temp_array[i] = temp_array[j]
                temp_array[j] = t

                permutation_sets.append(temp_array)

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
        find_max_sum(problem_queue)
    else:
        for sol in possible_solutions:
            print(get_permutations(sol))

def problem_solver(input_array):
    # Intializing the queue
    problem_queue = queue.Queue()
    problem_queue.put(input_array)

    # Passing the queue to the main method
    find_max_sum(problem_queue)


# Test function calls, output shoud be an integer
problem_solver([3,1,4,1])       # Expected output 4311
#problem_solver([3,1,4,1,5,9])   # Expected output 94311  
