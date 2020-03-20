#pragma once

#include "CGSocket.h"

#include <Network/Listener.h>
#include <Network/io_context_pool.h>

#include <Configuration/Configuration.h>

#include <memory>

class CGServer final
{
public:
	/**
	*  Our server constructor
	*\	Parameters is the loaded configuration
	*/
	CGServer(io_context_pool& pool);
	/**
	*  Our server destructor
	*/
	~CGServer();
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
	/**
	*	Register this server in lineid database
	*/
	void register_lineid();
	void update_lineid(const ServerState& state);

private:
	Listener<CGSocket>	network;
	boost::asio::io_context::strand strandPing;
	boost::asio::deadline_timer ping_timer;
};