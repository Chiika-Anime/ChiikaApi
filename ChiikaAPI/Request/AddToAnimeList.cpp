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
#include "Stable.h"
#include "AddToAnimeList.h"
#include "Database/LocalDataManager.h"
#include "Logging/ChiString.h"
#include "Root/Root.h"

//----------------------------------------------------------------------------
namespace ChiikaApi
{
	AddToAnimeListRequest::AddToAnimeListRequest()
	{
		m_sName = "AddToAnimeList";
	}
	//----------------------------------------------------------------------------
	AddToAnimeListRequest::~AddToAnimeListRequest()
	{
	}
	//----------------------------------------------------------------------------
	void AddToAnimeListRequest::OnSuccess()
	{
		pugi::xml_document doc;

		doc.load(m_Curl->GetResponse().c_str());


	}
	//----------------------------------------------------------------------------
	void AddToAnimeListRequest::OnError()
	{
		RequestInterface::OnError();
	}
	//----------------------------------------------------------------------------
	void AddToAnimeListRequest::Initialize()
	{
		m_Curl->Initialize();
		m_Curl->AddListener(this);
	}
	//----------------------------------------------------------------------------
	void AddToAnimeListRequest::SetPostData()
	{

	}
	//----------------------------------------------------------------------------
	void AddToAnimeListRequest::SetAnimeData(const UserAnimeEntry& anime)
	{
		m_Anime = anime;
	}
	//----------------------------------------------------------------------------
	void AddToAnimeListRequest::SetOptions()
	{
		/*ChiString url;
		int method;

		UserInfo ui = Root::Get()->GetLocalDataManager()->GetUserInfo();
		ChiString userName = ui.GetKeyValue(kUserName);
		ChiString passWord = ui.GetKeyValue(kPass);

		if (m_Anime.Anime.GetKeyValue(kSeriesAnimedbId) == "-1")
		{
			m_Curl->SetErrorCode(RequestCodes::BAD_PARAMETER);
			RequestInterface::OnError();
			return;
		}
		url = "http://myanimelist.net/api/animelist/add/" + (m_Anime.Anime.GetKeyValue(kSeriesAnimedbId)) + ".xml";
		method = CURLOPT_HTTPPOST;

		ChiStringUtil strUtil;
		ChiString postData = (GetAnimeXML(m_Anime));

		m_Curl->SetUrl(url);
		m_Curl->SetAuth(userName + ":" + passWord);
		m_Curl->SetVerbose(true);
		m_Curl->SetMethod(method, postData);*/
	}
	//----------------------------------------------------------------------------
	void AddToAnimeListRequest::Initiate()
	{
		
	}
	//----------------------------------------------------------------------------
}
//----------------------------------------------------------------------------