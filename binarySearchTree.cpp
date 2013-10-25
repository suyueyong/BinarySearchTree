{\rtf1\ansi\ansicpg1252\cocoartf1187\cocoasubrtf400
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red92\green38\blue153;\red0\green116\blue0;\red63\green110\blue116;\red28\green0\blue207;\red38\green71\blue75;
}
\margl1440\margr1440\vieww12100\viewh8420\viewkind0
\deftab529
\pard\tx529\pardeftab529\pardirnatural

\f0\fs22 \cf2 \CocoaLigature0 #include \cf3 <iostream>\cf2 \
\cf4 using\cf0  \cf4 namespace\cf0  \cf5 std\cf0 ;\
\cf2 #include \cf3 <vector>\cf2 \
\cf6 \
\cf4 class\cf0  BinaryTreeNode\{\
\cf4 private\cf0 :\
    \cf4 float\cf0  val;\
    \cf7 BinaryTreeNode\cf0  *left, *right;\
\cf4 public\cf0 :\
    BinaryTreeNode()\{\
        \cf7 val\cf0 =\cf8 0.0\cf0 ;\
        \cf7 left\cf0 =\cf4 NULL\cf0 ;\
        \cf7 right\cf0 =\cf4 NULL\cf0 ;\
    \}\
    BinaryTreeNode(\cf4 float\cf0  v)\{\
        \cf7 val\cf0 =v;\
        \cf7 left\cf0 =\cf4 NULL\cf0 ;\
        \cf7 right\cf0 =\cf4 NULL\cf0 ;\
    \}\
    BinaryTreeNode(\cf4 float\cf0  v, \cf7 BinaryTreeNode\cf0  *l, \cf7 BinaryTreeNode\cf0  *r)\{\
        \cf7 val\cf0 =v;\
        \cf7 left\cf0 =l;\
        \cf7 right\cf0 =r;\
    \}\
    \cf4 float\cf0  getVal()\{\
        \cf4 return\cf0  \cf7 val\cf0 ;\
    \}\
    \cf7 BinaryTreeNode\cf0  *getLeft()\{\
        \cf4 return\cf0  \cf7 left\cf0 ;\
    \}\
    \cf7 BinaryTreeNode\cf0  *getRight()\{\
        \cf4 return\cf0  \cf7 right\cf0 ;\
    \}\
    \cf4 void\cf0  setVal(\cf4 float\cf0  v)\{\
        \cf7 val\cf0 =v;\
    \}\
    \cf4 void\cf0  setLeft(\cf7 BinaryTreeNode\cf0  *l)\{\
        \cf7 left\cf0 =l;\
    \}\
    \cf4 void\cf0  setRight(\cf7 BinaryTreeNode\cf0  *r)\{\
        \cf7 right\cf0 =r;\
    \}\
    \
\};\
\
\cf4 class\cf0  BinarySearchTree\{\
\cf4 private\cf0 :\
    \cf7 BinaryTreeNode\cf0  *root;\
    \cf4 bool\cf0  lookupHelper(\cf7 BinaryTreeNode\cf0  *root, \cf4 float\cf0  v)\{\
        \cf4 if\cf0 (root==\cf4 NULL\cf0 ) \cf4 return\cf0  \cf4 false\cf0 ;\
        \cf4 if\cf0 (root->\cf9 getVal\cf0 ()==v) \cf4 return\cf0  \cf4 true\cf0 ;\
        \cf4 if\cf0 (v<root->\cf9 getVal\cf0 ())\{\
            \cf4 return\cf0  \cf9 lookupHelper\cf0 (root->\cf9 getLeft\cf0 (), v);\
        \}\
        \cf4 else\cf0 \{\
            \cf4 return\cf0  \cf9 lookupHelper\cf0 (root->\cf9 getRight\cf0 (), v);\
        \}\
    \}\
    \cf4 void\cf0  insertHelper(\cf7 BinaryTreeNode\cf0 * root, \cf4 float\cf0  v)\{\
        \cf4 if\cf0 (v==root->\cf9 getVal\cf0 ()) \cf4 return\cf0 ;\
        \cf4 if\cf0 (v<root->\cf9 getVal\cf0 ())\{\
            \cf4 if\cf0 (root->\cf9 getLeft\cf0 ()==\cf4 NULL\cf0 )\{\
                root->\cf9 setLeft\cf0 (\cf4 new\cf0  \cf7 BinaryTreeNode\cf0 (v, \cf4 NULL\cf0 , \cf4 NULL\cf0 ));\
            \}\
            \cf4 else\cf0  \cf9 insertHelper\cf0 (root->\cf9 getLeft\cf0 (), v);\
        \}\
        \cf4 else\cf0 \{\
            \cf4 if\cf0 (root->\cf9 getRight\cf0 ()==\cf4 NULL\cf0 )\{\
                root->\cf9 setRight\cf0 (\cf4 new\cf0  \cf7 BinaryTreeNode\cf0 (v, \cf4 NULL\cf0 , \cf4 NULL\cf0 ));\
            \}\
            \cf4 else\cf0  \cf9 insertHelper\cf0 (root->\cf9 getRight\cf0 (), v);\
        \}\
    \}\
    \cf7 BinaryTreeNode\cf0  *smallestTreeNode(\cf7 BinaryTreeNode\cf0  *root)\{\
        \cf4 if\cf0 (root->\cf9 getLeft\cf0 ()==\cf4 NULL\cf0 ) \cf4 return\cf0  root;\
        \cf4 else\cf0  \cf4 return\cf0  \cf9 smallestTreeNode\cf0 (root->\cf9 getLeft\cf0 ());\
    \}\
    \cf7 BinaryTreeNode\cf0  *deleteHelper(\cf7 BinaryTreeNode\cf0 * root, \cf4 float\cf0  v)\{\
        \cf4 if\cf0 (root==\cf4 NULL\cf0 ) \cf4 return\cf0  \cf4 NULL\cf0 ;\
        \cf4 if\cf0 (root->\cf9 getVal\cf0 ()==v)\{\
            \cf4 if\cf0 (root->\cf9 getLeft\cf0 ()==\cf4 NULL\cf0 &&root->\cf9 getRight\cf0 ()==\cf4 NULL\cf0 ) \cf4 return\cf0  \cf4 NULL\cf0 ;\
            \cf4 if\cf0 (root->\cf9 getLeft\cf0 ()==\cf4 NULL\cf0 ) \cf4 return\cf0  root->\cf9 getRight\cf0 ();\
            \cf4 if\cf0 (root->\cf9 getRight\cf0 ()==\cf4 NULL\cf0 ) \cf4 return\cf0  root->\cf9 getLeft\cf0 ();\
\
            \cf7 BinaryTreeNode\cf0  *tmp=\cf9 smallestTreeNode\cf0 (root->\cf9 getRight\cf0 ());\
            root->\cf9 setVal\cf0 (tmp->\cf9 getVal\cf0 ());\
            root->\cf9 setRight\cf0 (\cf9 deleteHelper\cf0 (root->\cf9 getRight\cf0 (), tmp->\cf9 getVal\cf0 ()) );\
            \cf4 return\cf0  root;\
            \
        \}\
        \cf4 if\cf0 (root->\cf9 getVal\cf0 ()>v)\{\
            root->\cf9 setLeft\cf0 (\cf9 deleteHelper\cf0 (root->\cf9 getLeft\cf0 (), v));\
            \cf4 return\cf0  root;\
        \}\
        \cf4 else\cf0 \{\
            root->\cf9 setRight\cf0 (\cf9 deleteHelper\cf0 (root->\cf9 getRight\cf0 (), v));\
            \cf4 return\cf0  root;\
        \}\
    \}\
    \
    \
        \
\cf4 public\cf0 :\
    \cf4 void\cf0  insertTreeNode(\cf4 float\cf0  v)\{\
        \cf4 if\cf0 (\cf7 root\cf0 ==\cf4 NULL\cf0 )\{\
            \cf7 root\cf0 =\cf4 new\cf0  \cf7 BinaryTreeNode\cf0 (v, \cf4 NULL\cf0 , \cf4 NULL\cf0 );\
        \}\
        \cf4 else\cf0 \{\
            \cf9 insertHelper\cf0 (\cf7 root\cf0 , v);\
        \}\
    \}\
    \cf4 void\cf0  deleteTreeNode(\cf4 float\cf0  v)\{\
        \cf7 root\cf0 =\cf9 deleteHelper\cf0 (\cf7 root\cf0 , v);\
        \
    \}\
    \cf4 bool\cf0  lookupTreeNode(\cf4 float\cf0  v)\{\
        \cf4 return\cf0  \cf9 lookupHelper\cf0 (\cf7 root\cf0 , v);\
    \}\
    \cf4 void\cf0  printTree()\{\
        \
    \}\
    \
\};}