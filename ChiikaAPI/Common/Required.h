//----------------------------------------------------------------------------
//Chiika Api
//Copyright (C) 2015  Alperen Gezer
//This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or
//(at your option) any later version.
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//You should have received a copy of the GNU General Public License along
//with this program; if not, write to the Free Software Foundation, Inc.,
//51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.*/
//----------------------------------------------------------------------------
#ifndef __Required_h__
#define __Required_h__
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
//----------------------------------------------------------------------------
#include "PlatformInformation.h"
//Generated by version.py
#include "ApiVersion.h"

//----------------------------------------------------------------------------
namespace ChiikaApi
{
	class ConfigManager;
	class MalManager;
	class RequestManager;
	class ThreadedRequest;
	class RequestListener;
	class AppSettings;
	class LocalDataInterface;
	class LocalDataManager;
	class AbstractNativeEventFilterHelper;
	class MediaPlayerRecognitionManager;
	class SeasonManager;
	class ParserInerface;
	class ParsingManager;
	class RequestInterface;
	class CurlEventListener;
	class CurlRequest;

	class MPRecognitionInterface;
	class AnimeRecognition;
	class SettingInterface;
	class ThreadManager;
}
//----------------------------------------------------------------------------
#include "StdHeaders.h"
//----------------------------------------------------------------------------
namespace ChiikaApi
{
	//----------------------------------------------------------------------------
	template <typename K,typename V,typename P = std::less<K> >
	struct Map
	{
#ifdef CHIIKA_STD_CONTAINERS_CUSTOM_MEMORY_ALLOCATOR
		typedef typename std::map<K,V,P,A> type;
		typedef typename std::map<K,V,P,A>::iterator iterator;
		typedef typename std::map<K,V,P,A>::const_iterator const_iterator;
#else
		typedef typename std::map<K,V,P> type;
		typedef typename std::map<K,V,P>::iterator iterator;
		typedef typename std::map<K,V,P>::const_iterator const_iterator;
#endif
	};
	//----------------------------------------------------------------------------
	template <typename K,typename V,typename P = std::less<K> >
	struct MultiMap
	{
#ifdef CHIIKA_STD_CONTAINERS_CUSTOM_MEMORY_ALLOCATOR
		typedef typename std::multimap<K,V,P,A> type;
		typedef typename std::multimap<K,V,P,A>::iterator iterator;
		typedef typename std::multimap<K,V,P,A>::const_iterator const_iterator;
#else
		typedef typename std::multimap<K,V,P> type;
		typedef typename std::multimap<K,V,P>::iterator iterator;
		typedef typename std::multimap<K,V,P>::const_iterator const_iterator;
#endif
	};
	//----------------------------------------------------------------------------
	template <typename T >
	struct Vector
	{
#ifdef CHIIKA_STD_CONTAINERS_CUSTOM_MEMORY_ALLOCATOR
		typedef typename std::vector<T,A> type;
		typedef typename std::vector<T,A>::iterator iterator;
		typedef typename std::vector<T,A>::const_iterator const_iterator;
#else
		typedef typename std::vector<T> type;
		typedef typename std::vector<T>::iterator iterator;
		typedef typename std::vector<T>::const_iterator const_iterator;
		typedef typename std::vector<T>::size_type size_t;
#endif
	};
	//----------------------------------------------------------------------------
	template <typename K,typename V> //std::pair doesnt allocate anything
	struct Pair
	{
#ifdef CHIIKA_STD_CONTAINERS_CUSTOM_MEMORY_ALLOCATOR
		typedef typename std::pair<K,V> type;
		typedef typename std::pair<K,V>::iterator iterator;
		typedef typename std::pair<K,V>::const_iterator const_iterator;
#else
		typedef typename std::pair<K,V> type;
		typedef typename std::pair<K,V>::iterator iterator;
		typedef typename std::pair<K,V>::const_iterator const_iterator;
#endif
	};
}
//----------------------------------------------------------------------------
namespace ChiikaApi
{
	typedef std::string _ChiStringBase;
	typedef std::basic_stringstream<char,std::char_traits<char>,std::allocator<char> > _ChiStringStreamBase;

	typedef _ChiStringBase ChiString;
	typedef _ChiStringStreamBase ChiStringStream;

	typedef Vector<ChiString>::type StringVector;
	typedef StringVector::size_type StringVectorSize;

	typedef Map<std::string,std::string>::type KeyMap;
}
//----------------------------------------------------------------------------
#	include "Common/UtilityDefines.h"
//----------------------------------------------------------------------------
namespace ChiikaApi
{
	enum RequestCodes
	{
		REQUEST_ERROR = 0x1 << 0,
		REQUEST_SUCCESS = 0x1 << 1,
		RETURNED_EMPTY = 0x1 << 2,
		POST_SUCCESS = 0x1 << 3,
		BAD_REQUEST = 0x1 << 4,
		INTERNAL_ERROR = 0x1 << 5,
		NOT_IMPLEMENTED = 0x1 << 6,
		UNAUTHORIZED = 0x1 << 7,
		NOT_KNOWN = 0x1 << 8,
		RETURNED_GOOD = 0x1 << 9,
		CANT_RESOLVE_HOST_OR_PROXY = 0x1 << 10,
		CANT_CONNECT = 0x1 << 11,
		BAD_PARAMETER = 0x1 << 12
	};
	enum CurlFlags
	{
		REQUEST_NORMAL = 0x1 << 0,
		REQUEST_DOWNLOAD = 0x1 << 1
	};

#include "Database/Globals.h"
	//----------------------------------------------------------------------------
#	define CHIKA_AUTO_MUTEX_NAME chitanda
#	define CHIKA_AUTO_MUTEX mutable boost::recursive_mutex CHIKA_AUTO_MUTEX_NAME;
#	define CHIKA_AUTO_MUTEX_LOCK boost::recursive_mutex::scoped_lock AutoMutexLock(CHIKA_AUTO_MUTEX_NAME)
}
//----------------------------------------------------------------------------
namespace //Move this to a header file later
{
	const int UnknownAnimeId = -1;
}
//----------------------------------------------------------------------------
#	include "Common/MyAnimeList.h"
#define ANIME_IN_LIST(x) (x.Anime.Id != 0)
//----------------------------------------------------------------------------
namespace ChiikaApi
{
	enum SystemEvents
	{
		CHIIKA_API_FS_READY = 0
	};
}
//----------------------------------------------------------------------------
#define ApiDebugMode
//#define ApiShowXMLOutput

#define FOR_(vector,var) \
						for(size_t var = 0; var < vector.size(); ++var) \

#endif // __Required_h__
