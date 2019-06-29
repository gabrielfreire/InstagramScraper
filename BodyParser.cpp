#include <iostream>
#include <vector>
#include "gumbo.h"

namespace html_parser {

	void extractMetas(GumboNode* node, std::vector<GumboNode>& metas) {
		if (node->type != GUMBO_NODE_ELEMENT) {
			return;
		}

		if (node->v.element.tag == GUMBO_TAG_META) {
			metas.push_back(*node);
		}
		GumboVector* children = &node->v.element.children;
		for (unsigned int i = 0; i < children->length; i++) {
			extractMetas(static_cast<GumboNode*>(children->data[i]), metas);
		}
	}

	void extractMetaContent(std::vector<GumboNode> metas, std::vector<std::string> &contents) {
		for (unsigned i = 0; i < metas.size(); i++) {
			GumboNode* meta = &metas[i];
			GumboAttribute* content = gumbo_get_attribute(&meta->v.element.attributes, "content");
			if (content != NULL) {
				contents.push_back(std::string(content->value));
			}
		}
	}

	std::string parse(std::string body) {
		try {

			GumboOutput* out = gumbo_parse(body.c_str());
			std::vector<GumboNode> metas;
			std::vector<std::string> contents;

			extractMetas(out->root, metas);

			extractMetaContent(metas, contents);

			return contents[12];
		}
		catch (std::exception& e) {
			std::cerr << e.what() << "\n";
		}
	}
}
