import subprocess
import time
import tracemalloc
import structure_generator


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


path_to_correct = ''
path_to_incorrect = ''
max_time_correct = 0
max_time_incorrect = 0
max_memory_correct = 0
max_memory_incorrect = 0
max_time_test_correct = ''
max_time_test_incorrect = ''
max_memory_test_correct = ''
max_memory_test_incorrect = ''

with open("stress.logs", 'w') as log_file:
    for test_number in range(None):  # Replace None with the number of tests
        input_data = ''  # Generate your input data structure (use functions from structure_generator.py)
        correct_solution = get_output_exe(path_to_correct, input_data)
        incorrect_solution = get_output_exe(path_to_incorrect, input_data)

        correct_output, correct_ecode, correct_time, correct_memory = correct_solution
        incorrect_output, incorrect_ecode, incorrect_time, incorrect_memory = incorrect_solution

        if correct_ecode != 0:
            log_file.write(f'{path_to_correct} finished with exit code {correct_ecode}\n')

        if correct_output == incorrect_output:
            log_file.write(f'OK {test_number}\n')
        else:
            log_file.write(f'WA {test_number}\n')
            log_file.write(f'Test data: {input_data}\n')
            log_file.write(f'Correct output: {correct_output}\n')
            log_file.write(f'Incorrect output: {incorrect_output}\n')

        # Track maximum time and memory usage for correct solution
        if correct_time > max_time_correct:
            max_time_correct = correct_time
            max_time_test_correct = input_data

        if incorrect_time > max_time_incorrect:
            max_time_incorrect = incorrect_time
            max_time_test_incorrect = input_data

        # Track maximum time and memory usage for incorrect solution
        if correct_memory > max_memory_correct:
            max_memory_correct = correct_memory
            max_memory_test_correct = input_data

        if incorrect_memory > max_memory_incorrect:
            max_memory_incorrect = incorrect_memory
            max_memory_test_incorrect = input_data

    log_file.write(f'Max time for correct solution: {max_time_correct} seconds\n')
    log_file.write(f'Test data for max time (correct solution): {max_time_test_correct}\n')
    log_file.write(f'Max memory for correct solution: {max_memory_correct} bytes\n')
    log_file.write(f'Test data for max memory (correct solution): {max_memory_test_correct}\n')

    log_file.write(f'Max time for incorrect solution: {max_time_incorrect} seconds\n')
    log_file.write(f'Test data for max time (incorrect solution): {max_time_test_incorrect}\n')
    log_file.write(f'Max memory for incorrect solution: {max_memory_incorrect} bytes\n')
    log_file.write(f'Test data for max memory (incorrect solution): {max_memory_test_incorrect}\n')
