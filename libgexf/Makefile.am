#AUTOMAKE_OPTIONS = foreign

h_sources = abstractiter.h abstractparser.h attributeiter.h attvalueiter.h conv.h data.h directedgraph.h dynamicgraph.h edgeiter.h exceptions.h filereader.h filewriter.h gexf.h gexfparser.h graph.h libgexf.h metadata.h nodeiter.h typedefs.h undirectedgraph.h rngvalidator.h schemavalidator.h memoryvalidator.h

cc_sources = abstractparser.cpp attributeiter.cpp attvalueiter.cpp conv.cpp data.cpp directedgraph.cpp dynamicgraph.cpp edgeiter.cpp filereader.cpp filewriter.cpp gexf.cpp gexfparser.cpp graph.cpp metadata.cpp nodeiter.cpp undirectedgraph.cpp rngvalidator.cpp schemavalidator.cpp memoryvalidator.cpp

library_includedir=$(includedir)/$(LIBRARY_NAME)
library_include_HEADERS = $(h_sources)

INCLUDES = $(XML2_CXXFLAGS) -I$(top_srcdir)

lib_LTLIBRARIES = libgexf.la

libgexf_la_SOURCES = $(h_sources) $(cc_sources)
libgexf_la_LIBS = $(XML2_LIBS)
