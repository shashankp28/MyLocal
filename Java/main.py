import subprocess

batcmd="java First Arvind"
result = subprocess.check_output(batcmd, shell=True)

print(result)