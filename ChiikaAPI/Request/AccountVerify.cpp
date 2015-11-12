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
#include "AccountVerify.h"
#include "Database\LocalDataManager.h"
//----------------------------------------------------------------------------
namespace ChiikaApi
{
	AccountVerifyRequest::AccountVerifyRequest()
	{
		m_sName = "Verify";
	}
	//----------------------------------------------------------------------------
	AccountVerifyRequest::~AccountVerifyRequest()
	{
	}
	//----------------------------------------------------------------------------
	void AccountVerifyRequest::OnSuccess()
	{
		pugi::xml_document doc;
		try
		{
			doc.load(m_Curl.GetResponse().c_str());
		}
		catch(...)
		{
			//Post error
		}
		pugi::xml_node  user = doc.child("user");
		ChiString userName = user.child("username").text().get();
		ChiString id = user.child("id").text().get();

		if(userInfo.UserName == userName)
		{
			userInfo.UserId = atoi(ToStd(id));
			userInfo.UserName = userName;

			LocalDataManager::Get().SetUserInfo(userInfo);
			RequestInterface::OnSuccess();
		}
	}
	//----------------------------------------------------------------------------
	void AccountVerifyRequest::OnError()
	{
		UserInfo ui;
		ui.UserId = UserInfo::UnknownUser;
		LocalDataManager::Get().SetUserInfo(userInfo);

		RequestInterface::OnError();
	}
	//----------------------------------------------------------------------------
	void AccountVerifyRequest::Initialize()
	{
		m_Curl.Initialize();
		m_Curl.AddListener(this);
	}
	//----------------------------------------------------------------------------
	void AccountVerifyRequest::SetUserInfo(UserInfo user)
	{
		userInfo = user;
	}
	//----------------------------------------------------------------------------
	void AccountVerifyRequest::SetOptions()
	{
		ChiString url;
		int method;
		ChiString userName;
		ChiString passWord;

		url = "http://myanimelist.net/api/account/verify_credentials.xml";
		method = CURLOPT_HTTPGET;
		userName = userInfo.UserName;
		passWord = userInfo.Pass;

		m_Curl.SetUrl(url);
		m_Curl.SetAuth(userName + ":" + passWord);
		m_Curl.SetMethod(method,"");
		m_Curl.SetWriteFunction(NULL);
	}
	//----------------------------------------------------------------------------
	void AccountVerifyRequest::Initiate()
	{
		m_Curl.Perform();
	}
	//----------------------------------------------------------------------------
}
//----------------------------------------------------------------------------