# File-based key-value data store
### Brief
A file-based key-value data store that supports the basic CRD (create, read, and delete) operations. This data store is meant to be used as a local storage for one single process on one machine. Refer [Unit Tests and Constraints.pdf](https://github.com/arnab01/File-Based-Storage-cpp/blob/master/Unit%20Tests%20and%20Constraints.pdf) for the output snapshots.

### Supports
The data store supports the following:
 1. It can be initialized using an optional file path. If one is not provided, it will reliably create itself in a reasonable location on the machine.
 2. A new key-value pair can be added to the data store using the Create operation. The key is capped at 32 characters. The value is capped at 16KB.
 3. If Create is invoked for an existing key, an appropriate error is returned.
 4. A Read operation on a key can be performed by providing the key, and receiving the value in response.
 5. A Delete operation can be performed by providing the key.
 6. Every key supports setting a Time-To-Live property when it is created. If provided, it will be evaluated as an integer defining the number of seconds the key to be retained
    in the data store. Once the Time-To-Live for a key has expired, the key will no longer be available for Read or Delete operations.
 7. Appropriate error responses is returned to a client if it uses the data store in unexpected ways or breaches any limits.
 8. Finally the size of the file storing data never exceeds 1GB and upon such attempt memory limitations must be conveyed to the user. 
 
### Usage
 To compile the code run the following commands in the terminal with g++ installed:
 1.  `g++ create.cpp insert.cpp main.cpp modify.cpp read.cpp util.cpp remove.cpp update.cpp -o main -std=c++17`
 2.  `.\main`
