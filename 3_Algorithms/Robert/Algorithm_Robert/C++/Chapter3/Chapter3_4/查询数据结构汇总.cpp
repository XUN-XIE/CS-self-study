/*

// Algorithm (Data Structure)	            worst-case cost (after N inserts)		average-case cost (after N random inserts)		key interface	            memory (bytes)
// 	                                        search	        insert	                search hit	        insert		
// Sequential Search (unordered list)	    N	            N	                    N/2	                N	                        equals()	                48N
// Binary Search (ordered array)		    lg(N)           N                       lg(N)		        N/2	                        compareTo()	                16N
// Binary tree Search (BST)	                N	            N			            1.39 * lg(N)        1.39 * lg(N)                compareTo()	                64N
// 2-3 tree search (red-black BST)			2lg(N)          2lg(N)		            1.00 * lg(N)        1.00 * lg(N)                compareTo()	                64N
// separate chaining (array of lists)		<lg(N)          <lg(N)		            N / (2 * M)         N/M	                        equals()    hashCode()	    48N + 64M
// linear probing (parallel arrays			c * lg(N)       c * lg(N)               <1.50	            <2.50	                    equals()    hashCode()	    between 32N and 128N

*/