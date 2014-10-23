
# This needs to be fixed but it kinda works for now
# just make sure that you are in the working test directory
all:
	git stash
	git pull
	/nobackup/jlwegene/mbed/workspace_tools/make.py -m NUCLEO_F401RE -t GCC_ARM -p 0
