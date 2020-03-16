#pragma once

#include "AuthSocket.h"

#include <Network/Listener.h>
#include <Network\io_context_pool.h>

#include <Configuration\Configuration.h>

#include <memory>

class AuthServer final
{
public:
	/**
	*  Our server constructor
	*\	Parameters is the loaded configuration
	*/
	AuthServer(io_context_pool& pool);
	/**
	*  Our server destructor
	*/
	~AuthServer();
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
	Listener<AuthSocket>	network;
	boost::asio::io_context::strand strandPing;
	boost::asio::deadline_timer ping_timer;
};