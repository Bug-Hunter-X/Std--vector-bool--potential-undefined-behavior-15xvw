std::vector<bool> vec; //This is where it gets tricky
vec.push_back(true); //No problems here
vec.push_back(false); //Still no problems
vec[0] = false; //This can cause problems on some compilers, or more specifically, some standard library implementations.
//The problems are based on the implementation details of how std::vector<bool> is specialized.
//Some implementations store booleans as bits in an array of ints, this is for space optimization.
//When accessing an element using the [] operator, you can end up with undefined behavior if you aren't careful.
//The other problem arises with the push_back method, where if you have a large number of elements,
//it might reallocate memory and change the location of the elements.
//The solution to this would be to avoid the use of std::vector<bool> or carefully check the implementation details
//of the standard library you are using.
