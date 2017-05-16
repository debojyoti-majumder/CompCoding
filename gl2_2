import queue

def is_divisable_by_three(arr):
    sum = 0

    for number in arr:
        sum = sum + number
    
    if sum % 3 == 0:
        return True
    else:
        return False

def find_max_sum(problem_queue):
    solution_found = False
    item = []
    to_be_tested = []

    while not problem_queue.empty():
        item = problem_queue.get()

        if is_divisable_by_three(item):
            print(item)
            solution_found = True
        else:
            to_be_tested.append(item)

    if solution_found == False :
        for so in to_be_tested:
            # Constructing the subset
            for n in so:
                sub_solution = item.copy()
                sub_solution.remove(n)

                problem_queue.put(sub_solution)
        
        # Recursive call to do BFS
        find_max_sum(problem_queue)


def problem_solver(input_array):
    problem_queue = queue.Queue()
    problem_queue.put(input_array)
    find_max_sum(problem_queue)


problem_solver([3,1,4,1])
problem_solver([3,1,4,1,5,9])
