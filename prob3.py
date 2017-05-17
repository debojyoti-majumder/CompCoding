
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

# Main method to perform the task
def find_min_distance(source, destination, turn_count):
    # Handle the base case
    if source == destination :
        return turn_count
    else:
        turn_count = turn_count+1

    # Get all possible valid moves
    moves = get_all_valid_moves(source)
    move_costs = []
    destination_found = False

    for m in moves:
        if m == destination:
            destination_found = True
            break
    
    if destination_found:
        return turn_count
    else:
        for m in moves:
            move_costs.append(find_min_distance(m,destination,turn_count))

    return min(move_costs)

print( find_min_distance(19, 36, 0 ) )              # Output should be 1
print( find_min_distance(0, 1, 0) )                 # Output should be 3
#print( find_min_distance(17, 1, 0) )                
