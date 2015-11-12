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
	class Log;
	class LogManager;
	class AppSettings;
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
}
//----------------------------------------------------------------------------
#include "StdHeaders.h"
#include "Memory\MemoryAllocator.h"
//----------------------------------------------------------------------------
namespace ChiikaApi
{
	//----------------------------------------------------------------------------
	template <typename K,typename V,typename P = std::less<K>,typename A = STLAllocator<std::pair<const K,V>,GeneralAllocPolicy> >
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
	template <typename K,typename V,typename P = std::less<K>,typename A = STLAllocator<std::pair<const K,V>,GeneralAllocPolicy> >
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
	template <typename T,typename A = STLAllocator<T,GeneralAllocPolicy> >
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
}
//----------------------------------------------------------------------------
#	include "Common/UtilityDefines.h"
//----------------------------------------------------------------------------
namespace ChiikaApi
{
	enum RequestCodes
	{
		REQUEST_ERROR = 0x1 << 0 ,
		REQUEST_SUCCESS = 0x1 << 1,
		RETURNED_EMPTY = 0x1 << 2,
		POST_SUCCESS = 0x1 << 3,
		BAD_REQUEST = 0x1 << 4,
		INTERNAL_ERROR = 0x1 << 5,
		NOT_IMPLEMENTED = 0x1 << 6,
		UNAUTHORIZED = 0x1 << 7,
		NOT_KNOWN = 0x1 << 8,
		RETURNED_GOOD = 0x1 << 9
	};

	//----------------------------------------------------------------------------
#	define CHIKA_AUTO_MUTEX_NAME chitanda
#	define CHIKA_AUTO_MUTEX /*mutable boost::recursive_mutex CHIKA_AUTO_MUTEX_NAME;*/ std::mutex CHIKA_AUTO_MUTEX_NAME;
#	define CHIKA_AUTO_MUTEX_LOCK /*boost::recursive_mutex::scoped_lock AutoMutexLock(CHIKA_AUTO_MUTEX_NAME);*/ std::unique_lock<std::mutex> AutoLock(CHIKA_AUTO_MUTEX_NAME,std::try_to_lock) ;
}
//----------------------------------------------------------------------------
#	include "Common/MyAnimeList.h"
#define ANIME_IN_LIST(x) (x.Anime.Id != 0)
//----------------------------------------------------------------------------
namespace ChiikaApi
{

}
#ifdef YUME_PLATFORM_WIN32
#include "windows.h"
#include "winbase.h"
#endif
//----------------------------------------------------------------------------
#define ApiDebugMode
//#define ApiShowXMLOutput

#endif // __Required_h__
