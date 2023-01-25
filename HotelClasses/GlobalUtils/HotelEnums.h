#pragma once

#ifndef HOTELENUMS_H
#define HOTELENUMS_H
#include <map>
#include <string>
#include <vector>
#include <iostream>

namespace MyEnums {

    ///* PAGE RELATED */

    enum AdminPages {
        AdminHome,
        AdminLogin,
        UserManagement,
        BookingManagement,
        RoomManagement,
        WorkerManagement,
        AdminControlPanel
    };

    enum ClientPages {
        ClientHome,
        ClientLogin,
        Registration,
        RoomBrowse,
        BookRoom,
        ViewBookings,
        ClientControlPanel
    };

    ///* ROOM RELATED */

    enum RoomType {
        Single,
        Double,
        Suite
    };

    enum BedType {
        SingleKid,
        Single120,
        Single140,
        DoubleBed,
        KingBed

    };

    ///* BOOKING RELATED */

    enum BookingStatus {
        Confirmed,
        Cancelled,
        Loading
    };

    enum PaymentMethod {
        CreditCard,
        Invoice,
        PayPal,
        Swish
    };

    enum CancellationPolicy {
        AnyTime, //free to cancell anytime
        Week, // 1 week free cancellation
        Month, // 1 month free cancellation
        FourtyEightHourBefor //need to cancell 48h before

    };

    ///* HOTEL MANAGEMENT RELATED*/

    enum Department {
        FrontOffice,
        HouseKeeping,
        FoodAndBeverage,
        SalesAndMarketing,
        Engineering,
        Security,
        Accounting,
        RevenueManagement,
        GuestServices,
        SpaAndWellnes

    };

    enum WorkPosition {
        Contractor,
        Hourly,
        Intern,
        Manager
    };

        enum WorkSchedule {
            fullTime,
            HalfTime,
            PartTime,
            SeasonalWorker,
            Hired
        };

        enum HotelArea {
            Lobby,
            GuestRooms,
            ConferenceRooms,
            Restaurants,
            Pool,
            FitnessCenter,
            Spa,
            BusinessCenter,
            Parking,
            GiftShop
        };

        ///* TIME RELATED *//
        enum months {
            January = 1,
            February,
            March,
            April,
            May,
            June,
            July,
            August,
            September,
            October,
            November,
            December
        };

        static const std::vector<unsigned int> daysOfMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        ///* Mapping */

        static std::map<AdminPages, std::string> adminPagesMap = {
                {AdminHome,         "AdminHome"},
                {AdminLogin,        "AdminLogin"},
                {UserManagement,    "UserManagement"},
                {BookingManagement, "BookingManagement"},
                {RoomManagement,    "RoomManagement"},
                {WorkerManagement,  "WorkerManagement"},
                {AdminControlPanel, "AdminControlPanel"}
        };

        static std::map<ClientPages, std::string> clientPagesMap = {
                {ClientHome,         "ClientHome"},
                {ClientLogin,        "ClientLogin"},
                {Registration,       "Registration"},
                {RoomBrowse,         "RoomBrowse"},
                {BookRoom,           "BookRoom"},
                {ViewBookings,       "ViewBookings"},
                {ClientControlPanel, "ClientControlPanel"}
        };

        static std::map<RoomType, std::string> roomTypeMap = {
                {Single, "Single"},
                {Double, "Double"},
                {Suite,  "Suite"}
        };

        static std::map<BedType, std::string> bedTypeMap = {
                {SingleKid, "SingleKid"},
                {Single120, "Single120"},
                {Single140, "Single140"},
                {DoubleBed, "DoubleBed"},
                {KingBed,   "KingBed"}
        };

        static std::map<BookingStatus, std::string> bookingStatusMap = {
                {Confirmed, "Confirmed"},
                {Cancelled, "Cancelled"},
                {Loading,   "Loading"}
        };

        static std::map<PaymentMethod, std::string> paymentMethodMap = {
                {CreditCard, "CreditCard"},
                {Invoice,    "Invoice"},
                {PayPal,     "PayPal"},
                {Swish,      "Swish"}
        };

        static std::map<CancellationPolicy, std::string> cancellationPolicyMap = {
                {AnyTime,              "AnyTime"},
                {Week,                 "Week"},
                {Month,                "Month"},
                {FourtyEightHourBefor, "FourtyEightHourBefor"}
        };

        static std::map<Department, std::string> departmentMap = {
                {FrontOffice,       "FrontOffice"},
                {HouseKeeping,      "HouseKeeping"},
                {FoodAndBeverage,   "FoodAndBeverage"},
                {SalesAndMarketing, "SalesAndMarketing"},
                {Engineering,       "Engineering"},
                {Security,          "Security"},
                {Accounting,        "Accounting"},
                {RevenueManagement, "RevenueManagement"},
                {GuestServices,     "GuestServices"},
                {SpaAndWellnes,     "SpaAndWellnes"}
        };

        static std::map<WorkSchedule, std::string> workScheduleMap = {
                {fullTime,       "fullTime"},
                {HalfTime,       "HalfTime"},
                {PartTime,       "PartTime"},
                {SeasonalWorker, "SeasonalWorker"},
                {Hired,          "Hired"}
        };

        static std::map<HotelArea, std::string> hotelAreaMap =
                {
                        {Lobby,           "Lobby"},
                        {GuestRooms,      "GuestRoom"},
                        {ConferenceRooms, "ConferenceRooms"},
                        {Restaurants,     "Resturants"},
                        {Pool,            "Pool"},
                        {FitnessCenter,   "FitnessCenter"},
                        {Spa,             "Spa"},
                        {BusinessCenter,  "BusinessCenter"},
                        {Parking,         "Parking"},
                        {GiftShop,        "GiftShop"}

                };
        static std::map<months, std::string> monthMap =
                {
                        {months::January,   "January"},
                        {months::February,  "February"},
                        {months::March,     "March"},
                        {months::April,     "April"},
                        {months::May,       "May"},
                        {months::June,      "June"},
                        {months::July,      "July"},
                        {months::August,    "August"},
                        {months::September, "September"},
                        {months::October,   "October"},
                        {months::November,  "November"},
                        {months::December,  "December"}
                };

}
#endif