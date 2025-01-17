import subprocess
import time
import tracemalloc
import structure_generator
import random
import string


# Function to run .exe program and get output, exit code, elapsed time, and memory usage
def get_output_exe(path: str, input_data: str):
    start_time = time.time()  # Start the timer
    tracemalloc.start()  # Start tracing memory allocation
    rn = subprocess.run(
        [path],
        input=input_data.encode(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    current, peak = tracemalloc.get_traced_memory()  # Get memory usage
    tracemalloc.stop()  # Stop tracing memory allocation
    elapsed_time = time.time() - start_time  # Calculate elapsed time
    rn_output = rn.stdout.decode()  # Decode output
    exit_code = rn.returncode  # Get exit code
    return rn_output, exit_code, elapsed_time, peak


# Function to run .py program and get output, exit code, elapsed time, and memory usage
def get_output_py(path: str, input_data: str):
    start_time = time.time()  # Start the timer
    tracemalloc.start()  # Start tracing memory allocation
    rn = subprocess.run(
        ["python", path],
        input=input_data.encode(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    current, peak = tracemalloc.get_traced_memory()  # Get memory usage
    tracemalloc.stop()  # Stop tracing memory allocation
    elapsed_time = time.time() - start_time  # Calculate elapsed time
    rn_output = rn.stdout.decode()  # Decode output
    exit_code = rn.returncode  # Get exit code
    return rn_output, exit_code, elapsed_time, peak


path_to_correct = ""
path_to_incorrect = ""
max_time_correct = 0
max_time_incorrect = 0
max_memory_correct = 0
max_memory_incorrect = 0
max_time_test_correct = ''
max_time_test_incorrect = ''
max_memory_test_correct = ''
max_memory_test_incorrect = ''


def gen_test():
    pass


with open("stress.logs", 'w') as log_file:
    for test_number in range(10000):  # Replace None with the number of tests
        input_data = gen_test()
        correct_solution = get_output_exe(path_to_correct, input_data)
        incorrect_solution = get_output_exe(path_to_incorrect, input_data)

        correct_output, correct_ecode, correct_time, correct_memory = correct_solution
        incorrect_output, incorrect_ecode, incorrect_time, incorrect_memory = incorrect_solution

        if correct_ecode != 0:
            print(f'RE {test_number}\n', f'Test data:\n{input_data}\n', f'Correct output:\n{correct_output}\n',
                  f'Incorrect output:\n{incorrect_output}\n', sep='\n')
            break

        cor = True
        if correct_output != incorrect_output:
            cor = False
        if cor:
            print('OK')
            pass
        else:
            print(f'WA {test_number}\n', f'Test data:\n{input_data}\n', f'Correct output:\n{correct_output}\n',
                  f'Incorrect output:\n{incorrect_output}\n', sep='\n')
            break

        if correct_time > max_time_correct:
            max_time_correct = correct_time
            max_time_test_correct = input_data

        if incorrect_time > max_time_incorrect:
            max_time_incorrect = incorrect_time
            max_time_test_incorrect = input_data

        if correct_memory > max_memory_correct:
            max_memory_correct = correct_memory
            max_memory_test_correct = input_data

        if incorrect_memory > max_memory_incorrect:
            max_memory_incorrect = incorrect_memory
            max_memory_test_incorrect = input_data

print(f'Max time for correct solution: {max_time_correct} seconds')
print(f'Test data for max time (correct solution): {max_time_test_correct}')
print(f'Max memory for correct solution: {max_memory_correct} bytes')
print(f'Test data for max memory (correct solution): {max_memory_test_correct}')

print(f'Max time for incorrect solution: {max_time_incorrect} seconds')
print(f'Test data for max time (incorrect solution): {max_time_test_incorrect}')
print(f'Max memory for incorrect solution: {max_memory_incorrect} bytes')
print(f'Test data for max memory (incorrect solution): {max_memory_test_incorrect}')
