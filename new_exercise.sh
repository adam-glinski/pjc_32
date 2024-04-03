cp -R 00-template $1
# Consider switching to gawk (gnu awk) so u can edit the file directly
awk '1;/# Subdirectories/{ print "add_subdirectory('$1')" }' CMakeLists.txt > tmp && mv tmp CMakeLists.txt
