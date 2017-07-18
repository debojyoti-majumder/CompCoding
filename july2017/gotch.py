def getKey(item):
    return item[0]

# Get Sorted time list
def get_sorted_time_info(timing_values):
    return sorted(timing_values, key=getKey)

# Helper function
def is_conflict(s1, e1, s2, e2):
  return ((s1 >= s2) and (s1 <= e2)) or ((e1 >= s2) and (e2 <= e2)) or (s1 <= s2) and (e1 >= e2)

# The main algorithm
def get_min_doc_count(timing_values):
    shipdoc_list = []

    for t in timing_values:
        # The shore is empty
        if len(shipdoc_list) == 0:
            shipdoc_list.append(t)
            continue
        
        # Need to find a place to doc the ship
        conflict = False
        
        for i in range(len(shipdoc_list)):
            doc = shipdoc_list[i]
            conflict = is_conflict(doc[0],doc[1],t[0],t[1])
            
            if conflict == False:
                shipdoc_list[i] = t                
                break
        
        if conflict:
            shipdoc_list.append(t)

    return len(shipdoc_list)

input_file = open('in.txt','r')
output_file = open('out.txt','w')

first_line = input_file.readline()
number_of_inputs = int(first_line)

for i in range(number_of_inputs):
    ship_info = input_file.readline()
    number_of_ships = int(ship_info)
    timing_values = []

    for j in range(number_of_ships):
        timing_info = input_file.readline()
        split_data = timing_info.split(' ')

        # Prasing the time information as integer
        time_info = []
        time_info.append(int(split_data[0]))
        time_info.append(int(split_data[1]))

        # Appending the values
        timing_values.append(time_info)
    
    sorted_time_info = get_sorted_time_info(timing_values)
    print(get_min_doc_count(sorted_time_info), file=output_file)

output_file.close()
