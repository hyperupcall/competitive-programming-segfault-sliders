# shellcheck shell=bash
dbg() {
	case $1 in
		p*) python3 -m pdb ./*.py ;;
		j*) jshell ./*.jav* ;;
		c*) gdb ./*.c ;;
		*) echo 'NOT FOUND' ;;
	esac
}
