/*! \file gexfparser.cpp
    \author sebastien heymann
    \date 22 juin 2009, 17:20
    \version 0.1
 */

#include "data.h"


/*
# Copyright (c) <2009> <Sebastien Heymann>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
*/

#include "gexfparser.h"
#include "filereader.h"
#include "conv.h"
#include <string>
using namespace std;

namespace libgexf {

GexfParser::GexfParser(): _last_id(), _tmp_attributes_class("") {
}

GexfParser::GexfParser(const GexfParser& orig): _last_id(orig._last_id), _tmp_attributes_class(orig._tmp_attributes_class) {
}

GexfParser::~GexfParser() {
    // do not delete _gexf, only Reader instance should do !!
}

//-----------------------------------------
void GexfParser::bind(GEXF* gexf) {
//-----------------------------------------
    _gexf = gexf;
}

/**
 * processNode:
 * @reader: the xmlReader
 *
 * Call the right processing method
 */
//-----------------------------------------
void GexfParser::processNode(xmlTextReaderPtr reader, const xmlChar* name) {
//-----------------------------------------
    if( !isProcessableNode(reader) ) return;
    
    if( xmlStrEqual(name, xmlCharStrdup("gexf")) == 1 ) {
        processGEXFNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("meta")) == 1 ) {
        processMetaNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("creator")) == 1 ) {
        processCreatorNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("description")) == 1 ) {
        processDescriptionNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("graph")) == 1 ) {
        processGraphNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("nodes")) == 1 ) {
        processNodesNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("node")) == 1 ) {
        processNodeNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("edges")) == 1 ) {
        processEdgesNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("edge")) == 1 ) {
        processEdgeNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("attributes")) == 1 ) {
        processAttributesNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("attribute")) == 1 ) {
        processAttributeNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("default")) == 1 ) {
        processAttributeDefaultNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("attvalues")) == 1 ) {
        processAttvaluesNode(reader);
    }
    else if( xmlStrEqual(name, xmlCharStrdup("attvalue")) == 1 ) {
        processAttvalueNode(reader);
    }
    // TODO: other xml nodes
}

//-----------------------------------------
void GexfParser::processGEXFNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        try {
            string xmlns = this->getStringAttribute(reader, "xmlns");
            _gexf->getMetaData().setXmlns( xmlns );
        } catch (exception &e) {
            cerr << "WARN " << e.what() << endl;
        }

        try {
            string xsi = this->getStringAttributeNS(reader, "xsi", "xmlns");
            _gexf->getMetaData().setXsi( xsi );
        } catch (exception &e) {
            cerr << "WARN " << e.what() << endl;
        }

        try {
            string schemaLocation = this->getStringAttributeNS(reader, "schemaLocation", "xsi");
            _gexf->getMetaData().setXsi( schemaLocation );
        } catch (exception &e) {
            cerr << "WARN " << e.what() << endl;
        }

        try {
            string version = this->getStringAttribute(reader, "version");
        _gexf->getMetaData().setVersion( version );
        } catch (exception &e) {
            cerr << "WARN " << e.what() << endl;
        }
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for GEXF node.");
    }

}

//-----------------------------------------
void GexfParser::processMetaNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        string lastmodifieddate= this->getStringAttribute(reader, "lastmodifieddate");
        _gexf->getMetaData().setLastModifiedDate( lastmodifieddate );
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Meta node.");
    }
}

//-----------------------------------------
void GexfParser::processCreatorNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasVal = xmlTextReaderHasValue(reader);
    if(hasVal == 1) {
        const xmlChar *value = xmlTextReaderConstValue(reader);
        if(value != NULL)
            _gexf->getMetaData().setCreator( Conv::xmlCharToStr(value) );
    }
    else if(hasVal  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasValue() for Creator node.");
    }
}

//-----------------------------------------
void GexfParser::processDescriptionNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasVal = xmlTextReaderHasValue(reader);
    if(hasVal == 1) {
        const xmlChar *value = xmlTextReaderConstValue(reader);
        if(value != NULL) {
            _gexf->getMetaData().setDescription( Conv::xmlCharToStr(value) );
        }
    }
    else if(hasVal  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasValue() for Description node.");
    }
}

//-----------------------------------------
void GexfParser::processGraphNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    _gexf->setGraphType(GRAPH_UNDIRECTED); /* default */
    
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        string mode = "static";
        try {
            mode = this->getStringAttribute(reader, "mode");
        } catch(exception &e) {
            cerr << "INFO " << "Unknown mode, static used." << endl;
        }
        if( mode.compare("dynamic") == 0 ) {
            // TODO
        }
        else { /* static used by default */
            // TODO
        }

        string defaultedgetype = this->getStringAttribute(reader, "defaultedgetype");
        if( defaultedgetype.compare("directed") == 0 ) {
            _gexf->setGraphType(GRAPH_DIRECTED);
        } else if( defaultedgetype.compare("mixed") == 0 ) {
            _gexf->setGraphType(GRAPH_MIXED);
        }
        else {
            cerr << "INFO " << "Unknown default edge type, undirected used." << endl;
        }
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Graph node.");
    }
}

//-----------------------------------------
void GexfParser::processNodesNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    // TODO, do nothing for the moment
}

//-----------------------------------------
void GexfParser::processNodeNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        t_id node_id = (t_id)this->getUnsignedIntAttribute(reader, "id");
        string label= this->getStringAttribute(reader, "label");

        _gexf->getUndirectedGraph().addNode( node_id );
        _gexf->getData().setLabel( node_id, label );
        _last_node_type = NODE;
        _last_id = node_id;
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Graph node.");
    }
}

//-----------------------------------------
void GexfParser::processEdgesNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    // TODO, do nothing for the moment
}

//-----------------------------------------
void GexfParser::processEdgeNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        t_id edge_id = (t_id)this->getUnsignedIntAttribute(reader, "id");
        t_id source = (t_id)this->getUnsignedIntAttribute(reader, "source");
        t_id target = (t_id)this->getUnsignedIntAttribute(reader, "target");
        unsigned int cardinal = 1;
        string tmp_type = "undirected";
        try {
            cardinal = this->getUnsignedIntAttribute(reader, "cardinal");
        } catch(exception &e) {
            // nothing to do
        }
        try {
            tmp_type = this->getStringAttribute(reader, "type");
        } catch(exception &e) {
            // nothing to do
        }

        t_edge_type type = EDGE_UNDIRECTED;
        if( _gexf->getGraphType() == GRAPH_DIRECTED || tmp_type.compare("directed") == 0 ) {
            type = EDGE_DIRECTED;
        }
        else if( tmp_type.compare("double") == 0 ) {
            type = EDGE_DOUBLE;
        }

        if(_gexf->getGraphType() == GRAPH_DIRECTED) {
            _gexf->getDirectedGraph().addEdge( edge_id, source, target, cardinal, type);
        }
        else { /*undirected or mixed, use undirected*/
            _gexf->getUndirectedGraph().addEdge( edge_id, source, target, cardinal, type);
        }
        _last_node_type = EDGE;
        _last_id = edge_id;
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Graph node.");
    }
}

//-----------------------------------------
void GexfParser::processAttributesNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        string attribute_class = this->getStringAttribute(reader, "class");
        if( attribute_class.compare("node") == 0 || attribute_class.compare("edge") == 0 ) {
            _tmp_attributes_class = attribute_class;
        }
        else {
            throw FileReaderException("Attributes node: unknown class");
        }
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Attributes node.");
    }
}

//-----------------------------------------
void GexfParser::processAttributeNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    int hasAttr = xmlTextReaderHasAttributes(reader);
    if(hasAttr == 1) {
        t_id attribute_id = (t_id)this->getUnsignedIntAttribute(reader, "id");
        string title = this->getStringAttribute(reader, "title");
        string tmp_type = this->getStringAttribute(reader, "type");
        t_attr_type type = STRING; /* internal default value */

        if( tmp_type.compare("integer") == 0 )
            type = INTEGER;
        else if( tmp_type.compare("double") == 0 )
            type = DOUBLE;
        else if( tmp_type.compare("float") == 0 )
            type = FLOAT;
        else if( tmp_type.compare("boolean") == 0 )
            type = BOOLEAN;
        else if( tmp_type.compare("list-string") == 0 )
            type = LIST_STRING;

        if(_tmp_attributes_class.compare("node") == 0) {
            _gexf->getData().addNodeAttributeColumn(attribute_id, title, type);
        }
        else if(_tmp_attributes_class.compare("edge") == 0) {
            _gexf->getData().addEdgeAttributeColumn(attribute_id, title, type);
        }
    }
    else if(hasAttr  == -1) {
        throw FileReaderException("An error occured in xmlTextReaderHasAttributes() for Graph node.");
    }
}

//-----------------------------------------
void GexfParser::processAttributeDefaultNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    // TODO, do nothing for the moment
}

//-----------------------------------------
void GexfParser::processAttvaluesNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    /* nothing to do */
}

//-----------------------------------------
void GexfParser::processAttvalueNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    t_id attribute_id = (t_id)this->getUnsignedIntAttribute(reader, "id");
    string value = this->getStringAttribute(reader, "value");

    if( _last_node_type == NODE ) {
        _gexf->getData().setNodeValue(_last_id, attribute_id, value);
    }
    else if( _last_node_type == EDGE ) {
        _gexf->getData().setEdgeValue(_last_id, attribute_id, value);
    }
}

//-----------------------------------------
bool GexfParser::isProcessableNode(xmlTextReaderPtr reader) {
//-----------------------------------------
    /* for XmlNodeType, see http://www.gnu.org/software/dotgnu/pnetlib-doc/System/Xml/XmlNodeType.html
     */
    int t = xmlTextReaderNodeType(reader);
    return t != 15 && t != 16 && t != 12 && t != 13 && t != 7;
}

//-----------------------------------------
string GexfParser::getStringAttribute(xmlTextReaderPtr reader, const char* name) {
//-----------------------------------------
    xmlChar* attr = xmlTextReaderGetAttribute(reader, xmlCharStrdup(name));
    if( attr != NULL )
        return Conv::xmlCharToStr(attr);
    else {
        stringstream ss;
        ss << "An error occured in xmlTextReaderGetAttribute(): no attribute " << name;
        throw FileReaderException(ss.str());
    }
}

//-----------------------------------------
string GexfParser::getStringAttributeNS(xmlTextReaderPtr reader, const char* name, const char* namespaceURI) {
//-----------------------------------------
    xmlChar* attr = xmlTextReaderGetAttributeNs(reader, xmlCharStrdup(name), xmlCharStrdup(namespaceURI));
    if( attr != NULL )
        return Conv::xmlCharToStr(attr);
    else {
        stringstream ss;
        ss << "An error occured in xmlTextReaderGetAttribute(): no attribute " << namespaceURI << ":" << name;
        throw FileReaderException(ss.str());
    }
}

//-----------------------------------------
unsigned int GexfParser::getUnsignedIntAttribute(xmlTextReaderPtr reader, const char* name) {
//-----------------------------------------
    xmlChar* attr = xmlTextReaderGetAttribute(reader, xmlCharStrdup(name));
    if( attr != NULL )
        return Conv::xmlCharToUnsignedInt(attr);
    else {
        stringstream ss;
        ss << "An error occured in xmlTextReaderGetAttribute(): no attribute " << name;
        throw FileReaderException(ss.str());
    }
}

} /* namespace libgexf */
