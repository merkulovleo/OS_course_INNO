if [ "$#" -ne 1 ] || [ "$1" -le 0 ] || [ "$1" -ge 4 ]; then
    echo "Usage: $0 <number_of_subscribers (1-3)>"
    exit 1
fi

n=$1

mkdir -p /tmp/ex1

./publisher $n &

for i in $(seq 1 $n); do
    ./subscriber $i &
done

wait