# This file was automatically generated by SWIG (http://www.swig.org).
# Version 1.3.39
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.
# This file is compatible with both classic and new-style classes.

from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_libgexf', [dirname(__file__)])
        except ImportError:
            import _libgexf
            return _libgexf
        if fp is not None:
            try:
                _mod = imp.load_module('_libgexf', fp, pathname, description)
            finally:
                fp.close()
                return _mod
    _libgexf = swig_import_helper()
    del swig_import_helper
else:
    import _libgexf
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


class SwigPyIterator(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SwigPyIterator, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SwigPyIterator, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _libgexf.delete_SwigPyIterator
    __del__ = lambda self : None;
    def value(self): return _libgexf.SwigPyIterator_value(self)
    def incr(self, n = 1): return _libgexf.SwigPyIterator_incr(self, n)
    def decr(self, n = 1): return _libgexf.SwigPyIterator_decr(self, n)
    def distance(self, *args): return _libgexf.SwigPyIterator_distance(self, *args)
    def equal(self, *args): return _libgexf.SwigPyIterator_equal(self, *args)
    def copy(self): return _libgexf.SwigPyIterator_copy(self)
    def next(self): return _libgexf.SwigPyIterator_next(self)
    def __next__(self): return _libgexf.SwigPyIterator___next__(self)
    def previous(self): return _libgexf.SwigPyIterator_previous(self)
    def advance(self, *args): return _libgexf.SwigPyIterator_advance(self, *args)
    def __eq__(self, *args): return _libgexf.SwigPyIterator___eq__(self, *args)
    def __ne__(self, *args): return _libgexf.SwigPyIterator___ne__(self, *args)
    def __iadd__(self, *args): return _libgexf.SwigPyIterator___iadd__(self, *args)
    def __isub__(self, *args): return _libgexf.SwigPyIterator___isub__(self, *args)
    def __add__(self, *args): return _libgexf.SwigPyIterator___add__(self, *args)
    def __sub__(self, *args): return _libgexf.SwigPyIterator___sub__(self, *args)
    def __iter__(self): return self
SwigPyIterator_swigregister = _libgexf.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)

class ReadLockException(Exception):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ReadLockException, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ReadLockException, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _libgexf.new_ReadLockException(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _libgexf.delete_ReadLockException
    __del__ = lambda self : None;
    def what(self): return _libgexf.ReadLockException_what(self)
ReadLockException_swigregister = _libgexf.ReadLockException_swigregister
ReadLockException_swigregister(ReadLockException)

class WriteLockException(Exception):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, WriteLockException, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, WriteLockException, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _libgexf.new_WriteLockException(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _libgexf.delete_WriteLockException
    __del__ = lambda self : None;
    def what(self): return _libgexf.WriteLockException_what(self)
WriteLockException_swigregister = _libgexf.WriteLockException_swigregister
WriteLockException_swigregister(WriteLockException)

class MessageExceptionBuilder(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MessageExceptionBuilder, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MessageExceptionBuilder, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_getmethods__["buildString"] = lambda x: _libgexf.MessageExceptionBuilder_buildString
    if _newclass:buildString = staticmethod(_libgexf.MessageExceptionBuilder_buildString)
    def abstractClass(self): return _libgexf.MessageExceptionBuilder_abstractClass(self)
    __swig_destroy__ = _libgexf.delete_MessageExceptionBuilder
    __del__ = lambda self : None;
MessageExceptionBuilder_swigregister = _libgexf.MessageExceptionBuilder_swigregister
MessageExceptionBuilder_swigregister(MessageExceptionBuilder)

def MessageExceptionBuilder_buildString(*args):
  return _libgexf.MessageExceptionBuilder_buildString(*args)
MessageExceptionBuilder_buildString = _libgexf.MessageExceptionBuilder_buildString

class Graph(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Graph, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Graph, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _libgexf.new_Graph(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _libgexf.delete_Graph
    __del__ = lambda self : None;
    def addNode(self, *args): return _libgexf.Graph_addNode(self, *args)
    def addEdge(self, *args): return _libgexf.Graph_addEdge(self, *args)
    def removeNode(self, *args): return _libgexf.Graph_removeNode(self, *args)
    def removeEdge(self, *args): return _libgexf.Graph_removeEdge(self, *args)
    def removeInEdges(self, *args): return _libgexf.Graph_removeInEdges(self, *args)
    def removeOutEdges(self, *args): return _libgexf.Graph_removeOutEdges(self, *args)
    def containsNode(self, *args): return _libgexf.Graph_containsNode(self, *args)
    def containsEdge(self, *args): return _libgexf.Graph_containsEdge(self, *args)
    def getNodeCount(self): return _libgexf.Graph_getNodeCount(self)
    def getEdgeCount(self): return _libgexf.Graph_getEdgeCount(self)
    def getDegree(self, *args): return _libgexf.Graph_getDegree(self, *args)
    def getNeighbors(self, *args): return _libgexf.Graph_getNeighbors(self, *args)
    def clear(self): return _libgexf.Graph_clear(self)
    def clearEdges(self, *args): return _libgexf.Graph_clearEdges(self, *args)
    def readLock(self): return _libgexf.Graph_readLock(self)
    def readUnlock(self): return _libgexf.Graph_readUnlock(self)
    def writeLock(self): return _libgexf.Graph_writeLock(self)
    def writeUnlock(self): return _libgexf.Graph_writeUnlock(self)
    def isReadLock(self): return _libgexf.Graph_isReadLock(self)
    def isWriteLock(self): return _libgexf.Graph_isWriteLock(self)
    def isUnlock(self): return _libgexf.Graph_isUnlock(self)
Graph_swigregister = _libgexf.Graph_swigregister
Graph_swigregister(Graph)

class DirectedGraph(Graph):
    __swig_setmethods__ = {}
    for _s in [Graph]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, DirectedGraph, name, value)
    __swig_getmethods__ = {}
    for _s in [Graph]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, DirectedGraph, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _libgexf.new_DirectedGraph(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _libgexf.delete_DirectedGraph
    __del__ = lambda self : None;
    def getInEdges(self, *args): return _libgexf.DirectedGraph_getInEdges(self, *args)
    def getOutEdges(self, *args): return _libgexf.DirectedGraph_getOutEdges(self, *args)
    def getSuccessors(self, *args): return _libgexf.DirectedGraph_getSuccessors(self, *args)
    def getPredecessors(self, *args): return _libgexf.DirectedGraph_getPredecessors(self, *args)
    def getInDegree(self, *args): return _libgexf.DirectedGraph_getInDegree(self, *args)
    def getOutDegree(self, *args): return _libgexf.DirectedGraph_getOutDegree(self, *args)
    def isSuccessor(self, *args): return _libgexf.DirectedGraph_isSuccessor(self, *args)
    def isPredecessor(self, *args): return _libgexf.DirectedGraph_isPredecessor(self, *args)
DirectedGraph_swigregister = _libgexf.DirectedGraph_swigregister
DirectedGraph_swigregister(DirectedGraph)

class UndirectedGraph(Graph):
    __swig_setmethods__ = {}
    for _s in [Graph]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, UndirectedGraph, name, value)
    __swig_getmethods__ = {}
    for _s in [Graph]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, UndirectedGraph, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _libgexf.new_UndirectedGraph(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _libgexf.delete_UndirectedGraph
    __del__ = lambda self : None;
UndirectedGraph_swigregister = _libgexf.UndirectedGraph_swigregister
UndirectedGraph_swigregister(UndirectedGraph)

class GEXF(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, GEXF, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, GEXF, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _libgexf.new_GEXF(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _libgexf.delete_GEXF
    __del__ = lambda self : None;
    def getUndirectedGraph(self): return _libgexf.GEXF_getUndirectedGraph(self)
    def getDirectedGraph(self): return _libgexf.GEXF_getDirectedGraph(self)
    __swig_setmethods__["_graph"] = _libgexf.GEXF__graph_set
    __swig_getmethods__["_graph"] = _libgexf.GEXF__graph_get
    if _newclass:_graph = _swig_property(_libgexf.GEXF__graph_get, _libgexf.GEXF__graph_set)
GEXF_swigregister = _libgexf.GEXF_swigregister
GEXF_swigregister(GEXF)



