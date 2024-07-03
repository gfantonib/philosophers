#!/usr/bin/env python3

import subprocess

# Constant args
program = ["../philo"]
valgrind = ["valgrind", "--leak-check=full", "--show-leak-kinds=all", "--track-origins=yes"]
valgrind_check = "All heap blocks were freed -- no leaks are possible"

# Colours
GREEN = "\033[32;1m"
RED = "\033[31;1m"
COLOR_LIMITER = "\033[0m"
colours = [GREEN, RED, COLOR_LIMITER]

# Make clean and Make
clean = ["make", "fclean", "-C", "../"]
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
make = ["make", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

# Creating args
# battery = ["str on list", "dup on list", "max on list", "nothing on list"]
arg_list = [["1", "2", "3"]]
stderr_ref_list = ["wrong argument count!\n"]

arg_list.append(["1", "2", "3", "4", "5", "6"])
stderr_ref_list.append("wrong argument count!\n")

arg_list.append(["1", "2", "3", "4", "5"])
stderr_ref_list.append("")

arg_list.append(["1", "2", "3", "4"])
stderr_ref_list.append("")

arg_list.append(["1", "a", "3", "4"])
stderr_ref_list.append("wrong argument type!\n")

# Runing and collecting output and error
stderr_list = []
stderr_val_list = []
for arg in arg_list:
	cmd = program + arg
	output = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	cmd_val = valgrind + cmd
	output_val = subprocess.run(cmd_val, stderr=subprocess.PIPE, text=True)
	stderr_list.append(output.stderr)
	stderr_val_list.append(output_val.stderr)
	
# Printing test check
i = 0
for err, err_val in zip(stderr_list, stderr_val_list):
	# print(f"{battery[i].upper()}")
	if (err == stderr_ref_list[i]):
		print(f"{colours[0]}{i + 1}/{len(arg_list)}.	OK{colours[2]}")
	else:
		print(f"{colours[1]}{i + 1}/{len(arg_list)}.	KO{colours[2]}")
		exit_status = 1
	if valgrind_check in err_val:
		print(f"{colours[0]}	MOK\n{colours[2]}")
	else:
		print(f"{colours[1]}	MKO\n{colours[2]}")
		exit_status = 1
	i = i + 1