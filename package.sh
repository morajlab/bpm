NAME="morajlab/bpm"
DESCRIPTION="Bash package manager"
VERSION="0.0.1-alpha.6"
BIN="packages/cli/bin"
DEPENDENCIES=(
  ["morajlab/log"]="*"
  ["morajlab/vv"]="*"
  ["jq"]=("apt" "*")
)
LICENSE="MIT"
KEYWORDS=(
  "bash"
  "script"
  "unix"
  "linux"
  "package"
  "manager"
  "shell"
)
AUTHOR=(
  ["name"]="Morteza Jamali"
  ["email"]="mortezajamali4241@gmail.com"
  ["website"]="https://moraj.ir"
)
REPOSITORY="https://github.com/morajlab/bpm"
