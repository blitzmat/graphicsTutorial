#include "TextureCache.h"
#include "ImageLoader.h"

#include <iostream>

namespace Bengine {
	TextureCache::TextureCache()
	{

	}

	TextureCache::~TextureCache()
	{

	}

	GLTexture TextureCache::getTexture(std::string texturePath)
	{
		// Lookup texture to see if its in map
		auto mit = _textureMap.find(texturePath);

		// check if it's not in map
		if (mit == _textureMap.end())
		{
			// Load texture
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);

			// Instert into map
			_textureMap.insert(make_pair(texturePath, newTexture));

			std::cout << "Loaded texture\n";

			return newTexture;
		}
		std::cout << "Loaded cache texture\n";

		return mit->second;
	}
}