SOURCE := $(wildcard src/*.cpp)

echo $(SOURCE)
for s in $(SOURCE)
do
    echo "$(s)"
done