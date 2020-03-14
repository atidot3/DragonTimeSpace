#pragma once

#include "CharSocket.h"

#include <Network/Listener.h>
#include <Network/WebRequestSocket.h>
#include <Network\io_context_pool.h>

#include <Configuration\Configuration.h>

#include <memory>

class CharServer final
{
public:
	/**
	*  Our server constructor
	*\	Parameters is the loaded configuration
	*/
	CharServer(io_context_pool& pool);
	/**
	*  Our server destructor
	*/
	~CharServer();
	/**
	*  Init all server data
	*/
	void Init(io_context_pool& pool);
	/**
	*	Start the listener
	*/
	void run();
private:
	/**
	*  Connect our server to the database
	*/
	void connectToDatabase();
	/**
	*	Ping database to keep connection alive
	*/
	void ping();
private:
	Listener<CharSocket>	network;
//	Listener<WebSocketRequest>	test;
	boost::asio::io_context::strand strandPing;
	boost::asio::deadline_timer ping_timer;
};