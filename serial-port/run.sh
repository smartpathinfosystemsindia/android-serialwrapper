javac -sourcepath .  -d build/classes *.java
sudo java  -Djava.library.path=$PWD -cp build/classes sample
