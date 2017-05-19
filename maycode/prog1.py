import Queue

def get_point_from_int(integer_value):
    row = integer_value / 8
    column = integer_value - (8 * row)

    return row,column

# Any value 0-63 is proper value -1 means the value is invalid
def int_value_from_point(row, column):
    # Boundary condition
    if row < 0 or column < 0 or row > 7 or column > 7:
        return -1

    return 8*row + column

def get_all_valid_moves(source):
    val = -1
    valid_moves = []

    x,y = get_point_from_int(source);

    val = int_value_from_point(x-2, y-1)
    if val != -1 :
        valid_moves.append(val)

    val = int_value_from_point(x-2, y+1)
    if val != -1 :
        valid_moves.append(val)

    val = int_value_from_point(x+2, y-1)
    if val != -1 :
        valid_moves.append(val)

    val = int_value_from_point(x+2, y+1)
    if val != -1 :
        valid_moves.append(val)

    val = int_value_from_point(x+1, y-2)
    if val != -1 :
        valid_moves.append(val)

    val = int_value_from_point(x-1, y-2)
    if val != -1 :
        valid_moves.append(val)

    val = int_value_from_point(x+1, y+2)
    if val != -1 :
        valid_moves.append(val)

    val = int_value_from_point(x-1, y+2)
    if val != -1 :
        valid_moves.append(val)

    # Returning all the valid moves
    return valid_moves

def find_move_distance(source, destination, cost_map):
    if source == destination:
        return cost_map[source]
    
    destination_found = False
    node_queue = Queue.Queue()
    node_queue.put(source)

    while not destination_found:
        node = node_queue.get()
        moves = get_all_valid_moves(node)

        for m in moves:
            if m == destination:
                destination_found = True
                cost_map[m] = cost_map[node] + 1
            else:
                if m not in cost_map:
                    node_queue.put(m)
                    cost_map[m] = cost_map[node] + 1
    
    return cost_map[destination]     

# Main method to perform the task
def find_min_distance(source, destination, visited_nodes, turn_count):
    
    if source == destination :
        return turn_count
    else:
        turn_count = turn_count+1

    # Get all possible valid moves
    moves = get_all_valid_moves(source)
    move_costs = []
    possible_solutions = []
    destination_found = False

    for m in moves:
        if m == destination:
            destination_found = True
            break
    
    if destination_found:
        return turn_count
    else:
        visited_nodes.append(source)

        for m in moves:
            found_count = visited_nodes.count(m)
            
            # Add to the queue if the node is node visited
            if found_count == 0:
                possible_solutions.append(m)

        for solution in possible_solutions:
            distance = find_min_distance(solution,destination,visited_nodes,turn_count)
            
            if distance != -1:
                move_costs.append(distance)

        if len(move_costs) > 0 :
            return min(move_costs)
        else:
            return -1

def answer(source, dest):
    visited_nodes = []
    cost_map = {}
    cost_map[source] = 0
    return find_move_distance(source, dest, cost_map)

print("Test case 0", answer(19, 36 ))              # Output should be 1
print("Test case 1", answer(0, 1))                 # Output should be 3
print("Test case 2", answer(17, 1))                # Output should be 2
print("Test case 3", answer(7, 56))                # Output should be 6
